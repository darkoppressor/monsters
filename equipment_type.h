/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
