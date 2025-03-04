/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "equipment_manager.h"
#include "game_data.h"
#include "game.h"

using namespace std;

EquipmentManager::EquipmentManager () {
    meleeWeapon = "";
    headArmor = "";
    torsoArmor = "";
    handArmor = "";
    legArmor = "";
    footArmor = "";
}
bool EquipmentManager::hasMeleeWeapon () const {
    return meleeWeapon.length() > 0;
}
const EquipmentType& EquipmentManager::getMeleeWeapon () const {
    return Game_Data::getEquipmentType(Game::getWorldName(), meleeWeapon);
}
bool EquipmentManager::hasHeadArmor () const {
    return headArmor.length() > 0;
}
const EquipmentType& EquipmentManager::getHeadArmor () const {
    return Game_Data::getEquipmentType(Game::getWorldName(), headArmor);
}
bool EquipmentManager::hasTorsoArmor () const {
    return torsoArmor.length() > 0;
}
const EquipmentType& EquipmentManager::getTorsoArmor () const {
    return Game_Data::getEquipmentType(Game::getWorldName(), torsoArmor);
}
bool EquipmentManager::hasHandArmor () const {
    return handArmor.length() > 0;
}
const EquipmentType& EquipmentManager::getHandArmor () const {
    return Game_Data::getEquipmentType(Game::getWorldName(), handArmor);
}
bool EquipmentManager::hasLegArmor () const {
    return legArmor.length() > 0;
}
const EquipmentType& EquipmentManager::getLegArmor () const {
    return Game_Data::getEquipmentType(Game::getWorldName(), legArmor);
}
bool EquipmentManager::hasFootArmor () const {
    return footArmor.length() > 0;
}
const EquipmentType& EquipmentManager::getFootArmor () const {
    return Game_Data::getEquipmentType(Game::getWorldName(), footArmor);
}

double EquipmentManager::getMass () const {
    double mass = 0.0;

    if (hasMeleeWeapon()) {
        mass += getMeleeWeapon().mass;
    }

    if (hasHeadArmor()) {
        mass += getHeadArmor().mass;
    }

    if (hasTorsoArmor()) {
        mass += getTorsoArmor().mass;
    }

    if (hasHandArmor()) {
        mass += getHandArmor().mass;
    }

    if (hasLegArmor()) {
        mass += getLegArmor().mass;
    }

    if (hasFootArmor()) {
        mass += getFootArmor().mass;
    }

    return mass;
}

void EquipmentManager::equip (const String& item, const TileCoords& position) {
    const EquipmentType& equipmentType = Game_Data::getEquipmentType(Game::getWorldName(), item);

    if (equipmentType.slot == "meleeWeapon") {
        if (hasMeleeWeapon()) {
            Game::addEquipment(position, meleeWeapon);
        }

        meleeWeapon = item;
    } else if (equipmentType.slot == "headArmor") {
        if (hasHeadArmor()) {
            Game::addEquipment(position, headArmor);
        }

        headArmor = item;
    } else if (equipmentType.slot == "torsoArmor") {
        if (hasTorsoArmor()) {
            Game::addEquipment(position, torsoArmor);
        }

        torsoArmor = item;
    } else if (equipmentType.slot == "handArmor") {
        if (hasHandArmor()) {
            Game::addEquipment(position, handArmor);
        }

        handArmor = item;
    } else if (equipmentType.slot == "legArmor") {
        if (hasLegArmor()) {
            Game::addEquipment(position, legArmor);
        }

        legArmor = item;
    } else if (equipmentType.slot == "footArmor") {
        if (hasFootArmor()) {
            Game::addEquipment(position, footArmor);
        }

        footArmor = item;
    }
}
