/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "consumable_manager.h"
#include "game_data.h"
#include "game.h"

using namespace std;

void ConsumableManager::add (const String& item, const TileCoords& position) {
    const ConsumableType& consumableType = Game_Data::getConsumableType(Game::getWorldName(), item);

    if (!consumables.count(item)) {
        consumables.emplace(item, 1);
    } else if (consumables.at(item) < consumableType.maximum) {
        consumables.at(item) = consumables.at(item) + 1;
    } else {
        Game::addConsumable(position, item);
    }
}

List<String> ConsumableManager::getKeys () const {
    List<String> keys;

    for (auto& consumable : consumables) {
        keys.push_back(consumable.first);
    }

    return keys;
}
Items ConsumableManager::getItemCount (const String& item) const {
    if (consumables.count(item)) {
        return consumables.at(item);
    } else {
        return 0u;
    }
}

bool ConsumableManager::canHold (const String& item) const {
    return !consumables.count(item) ||
           consumables.at(item) < Game_Data::getConsumableType(Game::getWorldName(), item).maximum;
}

bool ConsumableManager::hasHealingItem () const {
    for (auto& consumable : consumables) {
        if (Game_Data::getConsumableType(Game::getWorldName(), consumable.first).healing > 0) {
            return true;
        }
    }

    return false;
}
Health ConsumableManager::useHealingItem () {
    for (auto& consumable : consumables) {
        Health healing = Game_Data::getConsumableType(Game::getWorldName(), consumable.first).healing;

        if (healing > 0) {
            if (consumable.second == 1) {
                consumables.erase(consumable.first);
            } else {
                consumables.at(consumable.first) = consumables.at(consumable.first) - 1;
            }

            return healing;
        }
    }

    return 0;
}
