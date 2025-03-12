/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "equipment_type.h"

using namespace std;

EquipmentType::EquipmentType () {
    displayName = "";
    sprite = "";
    slot = "";
    mass = 0.0;
    damageChance = 0;
    damageType = "";
    minimumDamage = 0;
    maximumDamage = 0;
    range = 0;
    damageAvoidanceChance = 0;
    smashingDefense = 0;
    slashingDefense = 0;
    stabbingDefense = 0;
}
bool EquipmentType::operator> (const EquipmentType& equipmentType) const {
    if (slot == equipmentType.slot) {
        if (slot == "meleeWeapon") {
            return (minimumDamage + maximumDamage) / 2 >
                   (equipmentType.minimumDamage + equipmentType.maximumDamage) / 2;
        } else {
            return (smashingDefense + slashingDefense + stabbingDefense) / 3 >
                   (equipmentType.smashingDefense + equipmentType.slashingDefense + equipmentType.stabbingDefense) / 3;
        }
    } else {
        return false;
    }
}
