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
const Health Stats::NO_MAXIMUM_FOOD = -1;
const Health Stats::NO_MAXIMUM_WATER = -1;
const Health Stats::NO_HUNGER = -1;
const Health Stats::NO_THIRST = -1;
const double Stats::NO_MELEE_SKILL = -1.0;
const Chance Stats::NO_MELEE_DAMAGE_CHANCE = 0u;
const String Stats::NO_MELEE_ATTACK_DAMAGE_TYPE = "";
const Health Stats::NO_MELEE_ATTACK_MINIMUM_DAMAGE = -1;
const Health Stats::NO_MELEE_ATTACK_MAXIMUM_DAMAGE = -1;
const Tiles Stats::NO_MELEE_ATTACK_RANGE = 0;
const Count Stats::NO_MELEE_ATTACK_COOLDOWN = 0u;
const Count Stats::NO_MELEE_ATTACK_PREPARATION = 0u;
const double Stats::NO_DEFENSE_SKILL = -1.0;
const Chance Stats::NO_DAMAGE_AVOIDANCE_CHANCE = 0u;
const Health Stats::NO_SMASHING_DEFENSE = -1;
const Health Stats::NO_SLASHING_DEFENSE = -1;
const Health Stats::NO_STABBING_DEFENSE = -1;
const Tiles Stats::NO_GET_ITEM_RANGE = 0;
const Tiles Stats::NO_SIGHT_RANGE = 0;

Stats::Stats () {
    mass = NO_MASS;
    moveForce = NO_MOVE_FORCE;
    maximumSpeed = NO_MAXIMUM_SPEED;
    collisionSteps = NO_COLLISION_STEPS;
    maximumHealth = NO_MAXIMUM_HEALTH;
    maximumFood = NO_MAXIMUM_FOOD;
    maximumWater = NO_MAXIMUM_WATER;
    hunger = NO_HUNGER;
    thirst = NO_THIRST;
    meleeSkill = NO_MELEE_SKILL;
    meleeDamageChance = NO_MELEE_DAMAGE_CHANCE;
    meleeAttackDamageType = NO_MELEE_ATTACK_DAMAGE_TYPE;
    meleeAttackMinimumDamage = NO_MELEE_ATTACK_MINIMUM_DAMAGE;
    meleeAttackMaximumDamage = NO_MELEE_ATTACK_MAXIMUM_DAMAGE;
    meleeAttackRange = NO_MELEE_ATTACK_RANGE;
    meleeAttackCooldown = NO_MELEE_ATTACK_COOLDOWN;
    meleeAttackPreparation = NO_MELEE_ATTACK_PREPARATION;
    defenseSkill = NO_DEFENSE_SKILL;
    damageAvoidanceChance = NO_DAMAGE_AVOIDANCE_CHANCE;
    smashingDefense = NO_SMASHING_DEFENSE;
    slashingDefense = NO_SLASHING_DEFENSE;
    stabbingDefense = NO_STABBING_DEFENSE;
    getItemRange = NO_GET_ITEM_RANGE;
    sightRange = NO_SIGHT_RANGE;
    definesUndead = false;
    undead = false;
    definesCanGetItems = false;
    canGetItems = false;
    definesCanUseItems = false;
    canUseItems = false;
    definesHungers = false;
    hungers = false;
    definesThirsts = false;
    thirsts = false;
}
