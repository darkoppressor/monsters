/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "stats.h"

using namespace std;

const double Stats::NO_MASS = -1.0;
const double Stats::NO_MOVE_FORCE = -1.0;
const double Stats::NO_MAXIMUM_SPEED = -1.0;
const uint32 Stats::NO_COLLISION_STEPS = 0u;
const Health Stats::NO_MAXIMUM_HEALTH = -1;
const String Stats::NO_MELEE_ATTACK_DAMAGE_TYPE = "";
const Health Stats::NO_MELEE_ATTACK_MINIMUM_DAMAGE = -1;
const Health Stats::NO_MELEE_ATTACK_MAXIMUM_DAMAGE = -1;
const Tiles Stats::NO_MELEE_ATTACK_RANGE = 0;
const Count Stats::NO_MELEE_ATTACK_COOLDOWN = 0u;
const Count Stats::NO_MELEE_ATTACK_PREPARATION = 0u;
const Health Stats::NO_SMASHING_DEFENSE = -1;
const Health Stats::NO_SLASHING_DEFENSE = -1;
const Health Stats::NO_STABBING_DEFENSE = -1;
const Tiles Stats::NO_SIGHT_RANGE = 0;

Stats::Stats () {
    mass = NO_MASS;
    moveForce = NO_MOVE_FORCE;
    maximumSpeed = NO_MAXIMUM_SPEED;
    collisionSteps = NO_COLLISION_STEPS;
    maximumHealth = NO_MAXIMUM_HEALTH;
    meleeAttackDamageType = NO_MELEE_ATTACK_DAMAGE_TYPE;
    meleeAttackMinimumDamage = NO_MELEE_ATTACK_MINIMUM_DAMAGE;
    meleeAttackMaximumDamage = NO_MELEE_ATTACK_MAXIMUM_DAMAGE;
    meleeAttackRange = NO_MELEE_ATTACK_RANGE;
    meleeAttackCooldown = NO_MELEE_ATTACK_COOLDOWN;
    meleeAttackPreparation = NO_MELEE_ATTACK_PREPARATION;
    smashingDefense = NO_SMASHING_DEFENSE;
    slashingDefense = NO_SLASHING_DEFENSE;
    stabbingDefense = NO_STABBING_DEFENSE;
    sightRange = NO_SIGHT_RANGE;
    definesUndead = false;
    undead = false;
}
