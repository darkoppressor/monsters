/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "game.h"
#include "game_constants.h"

#include <render.h>
#include <game_window.h>
#include <sound_manager.h>
#include <object_manager.h>
#include <engine_data.h>
#include <log.h>
#include <engine_strings.h>
#include <engine.h>

using namespace std;

RNG Game::rng;
uint32 Game::frame = 0;
String Game::worldName = "";
List<List<Tile>> Game::tiles;
List<Creature> Game::creatures;
List<Item> Game::items;
List<Item> Game::newItems;
Quad Game::creatureQuadtree;
Quad Game::itemQuadtree;

RNG& Game::getRng () {
    return rng;
}
uint32 Game::getFrame () {
    return frame;
}

const String& Game::getWorldName () {
    return worldName;
}

Tiles Game::getWorldTileWidth () {
    return tiles.size();
}
Tiles Game::getWorldTileHeight () {
    return tiles.size() > 0 ? tiles[0].size() : 0;
}
Pixels Game::getWorldWidth () {
    return getWorldTileWidth() * Game_Constants::TILE_SIZE;
}
Pixels Game::getWorldHeight () {
    return getWorldTileHeight() * Game_Constants::TILE_SIZE;
}
Index Game::getCreatureCount () {
    return creatures.size();
}
Creature& Game::getCreature (const Index index) {
    if (index < creatures.size()) {
        return creatures[index];
    } else {
        Log::add_error("Error accessing creature '" + Strings::num_to_string(index) + "'");
        Engine::quit();
    }
}
void Game::handleCreatureDeath (const Index index) {
    for (auto& creature : creatures) {
        creature.handleCreatureDeath(index);
    }
}
Item& Game::getItem (const Index index) {
    if (index < items.size()) {
        return items[index];
    } else {
        Log::add_error("Error accessing item '" + Strings::num_to_string(index) + "'");
        Engine::quit();
    }
}
void Game::addEquipment (const TileCoords& position, const String& item) {
    newItems.push_back(Item(position, item, true));
}
void Game::addConsumable (const TileCoords& position, const String& item) {
    newItems.push_back(Item(position, item, false));
}
const Quad& Game::getCreatureQuadtree () {
    return creatureQuadtree;
}
const Quad& Game::getItemQuadtree () {
    return itemQuadtree;
}

void Game::clear_world () {
    frame = 0;
    worldName = "";
    tiles.clear();
    creatures.clear();
    items.clear();
    newItems.clear();
    creatureQuadtree.clear_tree();
    itemQuadtree.clear_tree();
}

void Game::generate_world () {
    clear_world();

    worldName = "default";
    tiles.resize(100, List<Tile>(100));

    for (size_t i = 0; i < 1; i++) {
        creatures.push_back(Creature(TileCoords(rng.random_range(0, 100), rng.random_range(0, 100)), "human",
                                     "humanCitizens"));
        creatures.back().getEquipment().equip("crowbar", creatures.back().getTilePosition());
        // creatures.back().getConsumables().add("medkit", creatures.back().getTilePosition());
    }

    for (size_t i = 0; i < 0; i++) {
        creatures.push_back(Creature(TileCoords(rng.random_range(0, 100), rng.random_range(0,
                                                                                           100)), "zombie", "zombies"));
    }

    for (size_t i = 0; i < 25; i++) {
        items.push_back(Item(TileCoords(rng.random_range(0, 100), rng.random_range(0, 100)), "medkit", false));
    }

    creatureQuadtree.setup(10, 5, 0, Collision_Rect<Pixels>(0.0, 0.0, getWorldWidth(), getWorldHeight()));
    itemQuadtree.setup(10, 5, 0, Collision_Rect<Pixels>(0.0, 0.0, getWorldWidth(), getWorldHeight()));
}

void Game::tick () {}

void Game::ai () {
    creatureQuadtree.clear_tree();
    itemQuadtree.clear_tree();

    for (Index i = 0; i < creatures.size(); i++) {
        creatureQuadtree.insert_object(creatures[i].getBox(), i);
    }

    for (Index i = 0; i < items.size(); i++) {
        itemQuadtree.insert_object(items[i].getBox(), i);
    }

    for (Index i = 0; i < creatures.size(); i++) {
        creatures[i].think(i);
        creatures[i].act(i);
    }
}

void Game::movement () {
    for (auto& creature : creatures) {
        creature.accelerate();
    }

    for (auto& creature : creatures) {
        creature.movement();
    }
}

void Game::events () {
    for (Index i = 0; i < items.size();) {
        if (!items[i].exists()) {
            items.erase(items.begin() + i);
        } else {
            i++;
        }
    }

    while (newItems.size() > 0) {
        items.push_back(newItems[0]);
        newItems.erase(newItems.begin());
    }

    ///Sound_Manager::set_listener(example_player.circle.x,example_player.circle.y,Game_Manager::camera_zoom);

    if (++frame == Engine::UPDATE_RATE) {
        frame = 0;
    }
}

void Game::animate () {
    for (auto& creature : creatures) {
        creature.animate();
    }

    for (auto& item : items) {
        item.animate();
    }
}

void Game::render () {
    for (const auto& creature : creatures) {
        creature.render();
    }

    for (const auto& item : items) {
        item.render();
    }
}

void Game::render_to_textures () {
    /**Rtt_Manager::set_render_target("example");
       ///Render something here
       Rtt_Manager::reset_render_target();*/
}

void Game::update_background () {}

void Game::render_background () {
    Render::render_rectangle(0.0, 0.0, Game_Window::width(), Game_Window::height(), 1.0, "ui_black");
}

bool Game::moveInputState (string direction) {
    if (Object_Manager::game_command_state(direction)) {
        return true;
    }

    if (direction == "up" &&
        Object_Manager::game_command_state("move_stick_vertical") < -Engine_Data::controller_dead_zone) {
        return true;
    } else if (direction == "down" &&
               Object_Manager::game_command_state("move_stick_vertical") > Engine_Data::controller_dead_zone) {
        return true;
    } else if (direction == "left" &&
               Object_Manager::game_command_state("move_stick_horizontal") < -Engine_Data::controller_dead_zone) {
        return true;
    } else if (direction == "right" &&
               Object_Manager::game_command_state("move_stick_horizontal") > Engine_Data::controller_dead_zone) {
        return true;
    }

    return false;
}
