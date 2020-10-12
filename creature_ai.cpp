/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "creature.h"
#include "game.h"
#include "game_data.h"
#include "game_constants.h"

#include <engine.h>
#include <engine_math.h>
#include <collision.h>
#include <sorting.h>
// QQQ
#include <log.h>

using namespace std;

void Creature::handleCreatureDeath (const Index index) {
    if (isAlive() && goal.exists()) {
        goal.handleCreatureDeath(index);
    }
}
bool Creature::canCheckForAiGoal (const Index index) const {
    return (Game::getFrame() + (index % Engine::UPDATE_RATE)) % Game_Constants::AI_GOAL_SELECTION_PERIOD == 0;
}
void Creature::considerUsingHealingItem (List<AiChoice>& choices) {
    if (health <= getMaximumHealth() / 2 && consumables.hasHealingItem()) {
        choices.push_back(AiChoice(AiGoal::Type::useHealingItem, 0));
    }
}
List<CreatureTarget> Creature::considerAttackingCreature (List<AiChoice>& choices, const Index index) {
    List<Index> nearbyCreatures;
    PixelBox sight = getSight();

    Game::getCreatureQuadtree().get_objects(nearbyCreatures, sight);
    List<CreatureTarget> validTargets;
    Indexes seen;

    for (const auto creatureIndex : nearbyCreatures) {
        if (!seen.count(creatureIndex)) {
            seen.emplace(creatureIndex);

            if (creatureIndex != index) {
                const Creature& creature = Game::getCreature(creatureIndex);

                if (creature.isAlive() && getRelationship(creature).getType() == Relationship::Type::hostile &&
                    Collision::check_rect(sight, creature.getBox())) {
                    Pixels distanceToCreature =
                        Math::get_distance_between_points(getPosition(), creature.getPosition());
                    validTargets.push_back(CreatureTarget(creatureIndex, distanceToCreature));
                }
            }
        }
    }

    if (validTargets.size() > 0) {
        choices.push_back(AiChoice(AiGoal::Type::attackCreatureMelee, 0));
    }

    return validTargets;
}
bool Creature::isItemDesired (const Item& item) {
    if (item.isEquipment()) {
        const EquipmentType& equipmentType = Game_Data::getEquipmentType(Game::getWorldName(), item.getType());

        if (equipmentType.slot == "meleeWeapon") {
            if (!equipment.hasMeleeWeapon() || equipmentType > equipment.getMeleeWeapon()) {
                return true;
            }
        }
    } else {
        if (consumables.canHold(item.getType())) {
            return true;
        }
    }

    return false;
}
List<ItemTarget> Creature::considerGettingItem (List<AiChoice>& choices) {
    List<Index> nearbyItems;
    PixelBox sight = getSight();

    Game::getItemQuadtree().get_objects(nearbyItems, sight);
    List<ItemTarget> validTargets;
    Indexes seen;

    for (const auto itemIndex : nearbyItems) {
        if (!seen.count(itemIndex)) {
            seen.emplace(itemIndex);
            const Item& item = Game::getItem(itemIndex);

            if (item.exists() && isItemDesired(item) && Collision::check_rect(sight, item.getBox())) {
                Pixels distanceToItem = Math::get_distance_between_points(getPosition(), item.getPosition());
                validTargets.push_back(ItemTarget(itemIndex, distanceToItem));
            }
        }
    }

    if (validTargets.size() > 0) {
        choices.push_back(AiChoice(AiGoal::Type::getItem, 0));
    }

    return validTargets;
}
void Creature::think (const Index index) {
    if (isAlive() && !goal.exists() && canCheckForAiGoal(index)) {
        List<AiChoice> choices;
        considerUsingHealingItem(choices);
        List<CreatureTarget> validCreatureTargets = considerAttackingCreature(choices, index);
        List<ItemTarget> validItemTargets = considerGettingItem(choices);

        if (choices.size() > 0) {
            Sorting::quick_sort(choices);
            Index choiceIndex = Game::getRng().weighted_random_range(0, choices.size() - 1, 0, RNG::Weight::NORMAL);

            if (choices[choiceIndex].getGoalType() == AiGoal::Type::useHealingItem) {
                goal.setUseHealingItem();
            } else if (choices[choiceIndex].getGoalType() == AiGoal::Type::attackCreatureMelee) {
                Sorting::quick_sort(validCreatureTargets);
                Index validTargetIndex = Game::getRng().weighted_random_range(0,
                                                                              validCreatureTargets.size() - 1, 0,
                                                                              RNG::Weight::NORMAL);
                goal.setAttackCreatureMelee(validCreatureTargets[validTargetIndex].getIndex());
            } else if (choices[choiceIndex].getGoalType() == AiGoal::Type::getItem) {
                Sorting::quick_sort(validItemTargets);
                Index validTargetIndex = Game::getRng().weighted_random_range(0,
                                                                              validItemTargets.size() - 1, 0,
                                                                              RNG::Weight::NORMAL);
                goal.setGetItem(validItemTargets[validTargetIndex].getIndex());
            }
        }
    }
}
void Creature::act (const Index index) {
    if (isAlive()) {
        if (!attack.isInProgress() && !attack.isCooled() && attack.cool()) {
            attack.stopCooling();
        }

        if (goal.exists()) {
            if (goal.isValid(consumables)) {
                if (goal.getType() == AiGoal::Type::useHealingItem) {
                    brake();
                    heal(consumables.useHealingItem());
                    goal.setNone();
                } else if (goal.getType() == AiGoal::Type::attackCreatureMelee) {
                    if (Math::get_distance_between_points(getPosition(),
                                                          goal.getTargetPosition()) <=
                        getMeleeAttackRange() * Game_Constants::TILE_SIZE) {
                        brake();

                        if (attack.isInProgress()) {
                            continueMeleeAttack(index);
                        } else if (attack.isCooled()) {
                            startMeleeAttack();
                        }
                    } else {
                        applyMoveForce(Math::get_angle_to_point(getPosition(), goal.getTargetPosition()));
                    }
                } else if (goal.getType() == AiGoal::Type::getItem) {
                    if (Math::get_distance_between_points(getPosition(),
                                                          goal.getTargetPosition()) <=
                        getGetItemRange() * Game_Constants::TILE_SIZE) {
                        brake();
                        Item& item = Game::getItem(goal.getTargetIndex());

                        if (item.isEquipment()) {
                            equipment.equip(item.getType(), getTilePosition());
                        } else {
                            // QQQ
                            Log::add_log("Consumable added");
                            consumables.add(item.getType(), getTilePosition());
                        }

                        item.collect();
                        goal.setNone();
                    } else {
                        applyMoveForce(Math::get_angle_to_point(getPosition(), goal.getTargetPosition()));
                    }
                }
            } else {
                goal.setNone();
                attack.stop();
                doNothing();
            }
        } else {
            doNothing();
        }
    } else {
        doNothing();
    }
}
void Creature::doNothing () {
    brake();
}
void Creature::startMeleeAttack () {
    attack.start((getMeleeAttackPreparation() * Engine::UPDATE_RATE) / 1000.0);
}
void Creature::continueMeleeAttack (const Index index) {
    if (attack.prepare()) {
        attack.stop();
        attack.startCooling((getMeleeAttackCooldown() * Engine::UPDATE_RATE) / 1000.0);
        meleeAttack(index, goal.getTargetIndex());
    }
}
