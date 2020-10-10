/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "creature.h"
#include "creature_target.h"
#include "game.h"
#include "game_constants.h"

#include <engine.h>
#include <engine_math.h>
#include <collision.h>
#include <sorting.h>

using namespace std;

void Creature::handleCreatureDeath (const Index index) {
    if (isAlive() && goal.exists()) {
        goal.handleCreatureDeath(index);
    }
}
bool Creature::canCheckForAiGoal (const Index index) const {
    return (Game::getFrame() + (index % Engine::UPDATE_RATE)) % Game_Constants::AI_GOAL_SELECTION_PERIOD == 0;
}
void Creature::think (const Index index) {
    if (isAlive() && canCheckForAiGoal(index)) {
        List<Index> nearbyCreatures;
        PixelBox sight = getSight();
        Game::getQuadtree().get_objects(nearbyCreatures, sight);
        List<CreatureTarget> validTargets;
        Indexes seen;

        for (const auto creatureIndex : nearbyCreatures) {
            if (!seen.count(creatureIndex)) {
                seen.emplace(creatureIndex);

                if (creatureIndex != index) {
                    const Creature& creature = Game::getCreature(creatureIndex);

                    if (creature.isAlive() && getRelationship(creature).getType() == Relationship::Type::hostile &&
                        Collision::check_rect(sight, creature.getBox())) {
                        Pixels distanceToCreature = Math::get_distance_between_points(
                            getPosition(), creature.getPosition());
                        validTargets.push_back(CreatureTarget(creatureIndex, distanceToCreature));
                    }
                }
            }
        }

        if (validTargets.size() > 0) {
            Sorting::quick_sort(validTargets);
            Index validTargetIndex = Game::getRng().weighted_random_range(0,
                                                                          validTargets.size() - 1, 0,
                                                                          RNG::Weight::NORMAL);
            goal.setAttackCreatureMelee(validTargets[validTargetIndex].getIndex());
        }
    }
}
void Creature::act (const Index index) {
    if (isAlive()) {
        if (!attack.isInProgress() && !attack.isCooled() && attack.cool()) {
            attack.stopCooling();
        }

        if (goal.exists()) {
            if (goal.isValid()) {
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
