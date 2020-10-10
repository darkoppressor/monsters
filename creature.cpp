/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "creature.h"
#include "game_data.h"
#include "game.h"
#include "game_constants.h"

using namespace std;

Pixels Creature::getCollisionReduction () const {
    return Game_Data::getRace(race).collisionReduction;
}
double Creature::getMass () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.mass != Stats::NO_MASS ? race.stats.mass : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.mass;
}
double Creature::getMoveForce () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.moveForce != Stats::NO_MOVE_FORCE ? race.stats.moveForce : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.moveForce;
}
double Creature::getMaximumSpeed () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.maximumSpeed != Stats::NO_MAXIMUM_SPEED ? race.stats.maximumSpeed : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.maximumSpeed;
}
uint32 Creature::getCollisionSteps () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.collisionSteps !=
           Stats::NO_COLLISION_STEPS ? race.stats.collisionSteps : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.collisionSteps;
}
String Creature::getMeleeAttackDamageType () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackDamageType !=
           Stats::NO_MELEE_ATTACK_DAMAGE_TYPE ? race.stats.meleeAttackDamageType : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackDamageType;
}
Health Creature::getMeleeAttackMinimumDamage () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackMinimumDamage !=
           Stats::NO_MELEE_ATTACK_MINIMUM_DAMAGE ? race.stats.meleeAttackMinimumDamage : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackMinimumDamage;
}
Health Creature::getMeleeAttackMaximumDamage () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackMaximumDamage !=
           Stats::NO_MELEE_ATTACK_MAXIMUM_DAMAGE ? race.stats.meleeAttackMaximumDamage : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackMaximumDamage;
}
Tiles Creature::getMeleeAttackRange () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackRange !=
           Stats::NO_MELEE_ATTACK_RANGE ? race.stats.meleeAttackRange : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackRange;
}
Count Creature::getMeleeAttackCooldown () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackCooldown !=
           Stats::NO_MELEE_ATTACK_COOLDOWN ? race.stats.meleeAttackCooldown : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackCooldown;
}
Count Creature::getMeleeAttackPreparation () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackPreparation !=
           Stats::NO_MELEE_ATTACK_PREPARATION ? race.stats.meleeAttackPreparation : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackPreparation;
}
Tiles Creature::getSightRange () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.sightRange != Stats::NO_SIGHT_RANGE ? race.stats.sightRange : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.sightRange;
}
bool Creature::isUndead () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.definesUndead ? race.stats.undead : Game_Data::getRaceCategory(Game::getWorldName(),
                                                                                     race.category).stats.undead;
}

const Relationship& Creature::getRelationship (const Creature& creature) const {
    return Game_Data::getFaction(Game::getWorldName(), this->faction).getRelationship(creature.getFaction());
}

Creature::Creature (const TileCoords& position, const String& race, const String& faction):PhysicsObject(position, Game_Data::getRace(
                                                                                                             race).sprite)
{
    this->race = race;
    this->faction = faction;
    health = getMaximumHealth();
}
String Creature::getRace () const {
    return race;
}
String Creature::getFaction () const {
    return faction;
}
Health Creature::getHealth () const {
    return health;
}
AiGoal Creature::getGoal () const {
    return goal;
}
Attack Creature::getAttack () const {
    return attack;
}

Health Creature::getMaximumHealth () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.maximumHealth != Stats::NO_MAXIMUM_HEALTH ? race.stats.maximumHealth : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.maximumHealth;
}
Health Creature::getSmashingDefense () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.smashingDefense !=
           Stats::NO_SMASHING_DEFENSE ? race.stats.smashingDefense : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.smashingDefense;
}
Health Creature::getSlashingDefense () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.slashingDefense !=
           Stats::NO_SLASHING_DEFENSE ? race.stats.slashingDefense : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.slashingDefense;
}
Health Creature::getStabbingDefense () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.stabbingDefense !=
           Stats::NO_STABBING_DEFENSE ? race.stats.stabbingDefense : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.stabbingDefense;
}

bool Creature::isAlive () const {
    return health > 0;
}
PixelBox Creature::getSight () const {
    Pixels sightRange = getSightRange() * Game_Constants::TILE_SIZE;
    PixelBox box = getBox();

    return PixelBox(box.center_x() - sightRange, box.center_y() - sightRange, sightRange * 2.0, sightRange * 2.0);
}

void Creature::meleeAttack (const Index index, const Index creatureIndex) {
    Damage counterattack =
        Game::getCreature(creatureIndex).takeDamage(creatureIndex,
                                                    Damage(getMeleeAttackDamageType(),
                                                           Game::getRng().random_range(getMeleeAttackMinimumDamage(),
                                                                                       getMeleeAttackMaximumDamage())));

    if (counterattack.getAmount() > 0) {
        takeDamage(index, counterattack);
    }
}
Damage Creature::takeDamage (const Index index, const Damage& damage) {
    Health damageTaken = damage.getModifiedAmount(Game::getCreature(index));

    if (damageTaken >= health) {
        health = 0;
        die(index);

        return Damage("", 0);
    } else {
        health -= damageTaken;

        return Damage(getMeleeAttackDamageType(),
                      Game::getRng().random_range(getMeleeAttackMinimumDamage(), getMeleeAttackMaximumDamage()));
    }
}
void Creature::die (const Index index) {
    goal.setNone();
    attack.stop();

    Game::handleCreatureDeath(index);

    if (!isUndead()) {
        const World& world = Game_Data::getWorld(Game::getWorldName());

        if (world.deadBecomeRace.length() > 0) {
            race = world.deadBecomeRace;
            health = getMaximumHealth();
            setSprite(Game_Data::getRace(race).sprite);
        }

        if (world.deadBecomeFaction.length() > 0) {
            faction = world.deadBecomeFaction;
        }
    }

    if (!isAlive()) {
        setSprite("dead");
    }
}

void Creature::applyMoveForce (double angle) {
    PhysicsObject::applyMoveForce(getMoveForce(), angle);
}
void Creature::brake () {
    PhysicsObject::brake(getMoveForce(), getMass());
}
void Creature::accelerate () {
    PhysicsObject::accelerate(getMass(), getMaximumSpeed());
}
void Creature::movement () {
    PhysicsObject::movement(getCollisionSteps(), getCollisionReduction());
}
