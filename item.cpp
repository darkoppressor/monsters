/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "item.h"
#include "game_data.h"
#include "game.h"

using namespace std;

Item::Item (const TileCoords& position, const String& type, const bool equipment):PhysicsObject(position, equipment ? Game_Data::getEquipmentType(
                                                                                                    Game::getWorldName(),
                                                                                                    type).sprite : Game_Data::getConsumableType(
                                                                                                    Game::getWorldName(),
                                                                                                    type).sprite) {
    this->type = type;
    this->equipment = equipment;
    collected = false;
}
String Item::getType () const {
    return type;
}
bool Item::isEquipment () const {
    return equipment;
}
bool Item::exists () const {
    return !collected;
}
void Item::collect () {
    collected = true;
}
