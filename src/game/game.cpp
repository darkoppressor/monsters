/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "game.h"
#include "game_constants.h"

#include <render/render.h>
#include <game_window.h>
#include <sound/sound_manager.h>
#include <data/object_manager.h>
#include <data/engine_data.h>
#include <log.h>
#include <strings/engine_strings.h>
#include <engine.h>

using namespace std;

RNG Game::rng;
uint32 Game::frame = 0;
String Game::worldName = "";
Calendar Game::calendar;
List<List<Tile>> Game::tiles;
List<Creature> Game::creatures;
List<Creature> Game::newCreatures;
uint32 Game::deadCreatures = 0;
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
    deadCreatures++;

    for (auto& creature : creatures) {
        creature.handleCreatureDeath(index);
    }
}
void Game::handleCreatureDeletion (const Index index) {
    deadCreatures--;

    for (auto& creature : creatures) {
        creature.handleCreatureDeletion(index);
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
void Game::handleItemCollection (const Index index) {
    for (auto& creature : creatures) {
        creature.handleItemCollection(index);
    }
}
void Game::handleItemDeletion (const Index index) {
    for (auto& creature : creatures) {
        creature.handleItemDeletion(index);
    }
}
void Game::addCreature (const TileCoords& position, const String& race, const String& faction) {
    newCreatures.push_back(Creature(position, race, faction));
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
    calendar.reset();
    tiles.clear();
    creatures.clear();
    newCreatures.clear();
    deadCreatures = 0;
    items.clear();
    newItems.clear();
    creatureQuadtree.clear_tree();
    itemQuadtree.clear_tree();
}

void Game::generate_world () {
    clear_world();

    worldName = "default";
    tiles.resize(100, List<Tile>(100));

    for (size_t i = 0; i < 25; i++) {
        addCreature(TileCoords(rng.random_range(0, getWorldTileWidth()), rng.random_range(0, getWorldTileHeight())),
                    "human", "humanCitizens");
        newCreatures.back().getEquipment().equip("crowbar", newCreatures.back().getTilePosition());
        newCreatures.back().getConsumables().add("medkit", newCreatures.back().getTilePosition());
        newCreatures.back().getConsumables().add("cheeseburger", newCreatures.back().getTilePosition());
        newCreatures.back().getConsumables().add("waterBottle", newCreatures.back().getTilePosition());
    }

    for (size_t i = 0; i < 50; i++) {
        addCreature(TileCoords(rng.random_range(0, getWorldTileWidth()), rng.random_range(0, getWorldTileHeight())),
                    "zombie", "zombies");
    }

    for (size_t i = 0; i < 1; i++) {
        addEquipment(TileCoords(rng.random_range(0, getWorldTileWidth()), rng.random_range(0, getWorldTileHeight())),
                     "crowbar");
    }

    for (size_t i = 0; i < 25; i++) {
        addConsumable(TileCoords(rng.random_range(0, getWorldTileWidth()), rng.random_range(0, getWorldTileHeight())),
                      "medkit");
    }

    for (size_t i = 0; i < 10; i++) {
        addConsumable(TileCoords(rng.random_range(0, getWorldTileWidth()), rng.random_range(0, getWorldTileHeight())),
                      "cheeseburger");
    }

    for (size_t i = 0; i < 5; i++) {
        addConsumable(TileCoords(rng.random_range(0, getWorldTileWidth()), rng.random_range(0, getWorldTileHeight())),
                      "waterBottle");
    }

    creatureQuadtree.setup(10, 5, 0, Collision_Rect<Pixels>(0.0, 0.0, getWorldWidth(), getWorldHeight()));
    itemQuadtree.setup(10, 5, 0, Collision_Rect<Pixels>(0.0, 0.0, getWorldWidth(), getWorldHeight()));
}

void Game::tick () {
    Tick tick = calendar.tick();

    if (tick.getType() == Tick::Type::minute) {
        for (auto& creature : creatures) {
            creature.handleCalendarMinute();
        }
    } else if (tick.getType() == Tick::Type::hour) {
        for (Index i = 0; i < creatures.size(); i++) {
            creatures[i].handleCalendarHour(i);
        }
    } else if (tick.getType() == Tick::Type::day) {
        // TODO Does anything happen daily?
    }
}

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
    for (Index i = 0; deadCreatures > Game_Constants::MAXIMUM_DEAD_BODIES && i < creatures.size();) {
        if (!creatures[i].isAlive()) {
            handleCreatureDeletion(i);
            creatures.erase(creatures.begin() + i);
        } else {
            i++;
        }
    }

    for (Index i = 0; i < items.size();) {
        if (!items[i].exists()) {
            handleItemDeletion(i);
            items.erase(items.begin() + i);
        } else {
            i++;
        }
    }

    while (newCreatures.size() > 0) {
        creatures.push_back(newCreatures[0]);
        newCreatures.erase(newCreatures.begin());
    }

    while (newItems.size() > 0) {
        items.push_back(newItems[0]);
        newItems.erase(newItems.begin());
    }

    // Sound_Manager::set_listener(example_player.circle.x,example_player.circle.y,Game_Manager::camera_zoom);

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
       // Render something here Rtt_Manager::reset_render_target();*/
}

void Game::update_background () {
}

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
