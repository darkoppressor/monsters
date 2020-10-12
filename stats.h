/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef stats_h
#define stats_h

#include "base_types.h"

class Stats {
    public:
        static const double NO_MASS;
        static const double NO_MOVE_FORCE;
        static const double NO_MAXIMUM_SPEED;
        static const uint32 NO_COLLISION_STEPS;
        static const Health NO_MAXIMUM_HEALTH;
        static const String NO_MELEE_ATTACK_DAMAGE_TYPE;
        static const Health NO_MELEE_ATTACK_MINIMUM_DAMAGE;
        static const Health NO_MELEE_ATTACK_MAXIMUM_DAMAGE;
        static const Tiles NO_MELEE_ATTACK_RANGE;
        static const Count NO_MELEE_ATTACK_COOLDOWN;
        static const Count NO_MELEE_ATTACK_PREPARATION;
        static const Health NO_SMASHING_DEFENSE;
        static const Health NO_SLASHING_DEFENSE;
        static const Health NO_STABBING_DEFENSE;
        static const Tiles NO_GET_ITEM_RANGE;
        static const Tiles NO_SIGHT_RANGE;
        // kilograms
        double mass;
        // newtons
        double moveForce;
        // meters / second
        double maximumSpeed;
        uint32 collisionSteps;
        Health maximumHealth;
        String meleeAttackDamageType;
        Health meleeAttackMinimumDamage;
        Health meleeAttackMaximumDamage;
        // tiles
        Tiles meleeAttackRange;
        // milliseconds
        Count meleeAttackCooldown;
        // milliseconds
        Count meleeAttackPreparation;
        Health smashingDefense;
        Health slashingDefense;
        Health stabbingDefense;
        // tiles
        Tiles getItemRange;
        // tiles
        Tiles sightRange;
        bool definesUndead;
        bool undead;

        Stats ();
};

#endif
