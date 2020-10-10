/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "equipment_manager.h"
#include "game_data.h"
#include "game.h"

using namespace std;

EquipmentManager::EquipmentManager () {
    meleeWeapon = "";
}
bool EquipmentManager::hasMeleeWeapon () const {
    return meleeWeapon.length() > 0;
}
const EquipmentType& EquipmentManager::getMeleeWeapon () const {
    return Game_Data::getEquipmentType(Game::getWorldName(), meleeWeapon);
}

double EquipmentManager::getMass () const {
    double mass = 0.0;

    if (hasMeleeWeapon()) {
        mass += getMeleeWeapon().mass;
    }

    return mass;
}

void EquipmentManager::equip (const String& item) {
    const EquipmentType& equipmentType = Game_Data::getEquipmentType(Game::getWorldName(), item);

    if (equipmentType.slot == "meleeWeapon") {
        if (hasMeleeWeapon()) {
            // QQQ Drop current item
        }

        meleeWeapon = item;
    }
}
