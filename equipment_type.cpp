/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
}
bool EquipmentType::operator> (const EquipmentType& equipmentType) const {
    return (minimumDamage + maximumDamage) / 2 > (equipmentType.minimumDamage + equipmentType.maximumDamage) / 2;
}
