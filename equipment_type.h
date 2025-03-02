/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef equipment_type_h
#define equipment_type_h

#include "base_types.h"

class EquipmentType {
    public:
        String displayName;
        String sprite;
        String slot;
        double mass;
        // [0, 100]
        Chance damageChance;
        String damageType;
        Health minimumDamage;
        Health maximumDamage;
        Tiles range;
        // [0, 100]
        Chance damageAvoidanceChance;
        Health smashingDefense;
        Health slashingDefense;
        Health stabbingDefense;

        EquipmentType ();

        bool operator> (const EquipmentType& equipmentType) const;
};

#endif
