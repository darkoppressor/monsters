/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "game_data.h"

#include <engine.h>
#include <data_manager.h>
#include <data_reader.h>
#include <log.h>
#include <engine_strings.h>

#include <boost/algorithm/string.hpp>

using namespace std;

UnorderedMap<String, World> Game_Data::worlds;
UnorderedMap<String, Race> Game_Data::races;

///Don't forget to increment this for each progress item in load_data_game() below
const int Game_Data::game_data_load_item_count = 2;
void Game_Data::load_data_game (Progress_Bar& bar) {
    bar.progress("Loading worlds");
    Data_Manager::load_data("world");
    bar.progress("Loading races");
    Data_Manager::load_data("race");
}

void Game_Data::load_data_tag_game (string tag, File_IO_Load* load) {
    if (tag == "world") {
        loadWorld(load);
    } else if (tag == "race") {
        loadRace(load);
    }
}

void Game_Data::unload_data_game () {
    worlds.clear();
    races.clear();
}

bool Game_Data::loadStat (string& line, Stats& stats) {
    if (Data_Reader::check_prefix(line, "mass:")) {
        stats.mass = Strings::string_to_double(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "moveForce:")) {
        stats.moveForce = Strings::string_to_double(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "maximumSpeed:")) {
        stats.maximumSpeed = Strings::string_to_double(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "collisionSteps:")) {
        stats.collisionSteps = Strings::string_to_unsigned_long(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "maximumHealth:")) {
        stats.maximumHealth = Strings::string_to_unsigned_long(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "meleeAttackDamageType:")) {
        stats.meleeAttackDamageType = line;

        return true;
    } else if (Data_Reader::check_prefix(line, "meleeAttackMinimumDamage:")) {
        stats.meleeAttackMinimumDamage = Strings::string_to_unsigned_long(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "meleeAttackMaximumDamage:")) {
        stats.meleeAttackMaximumDamage = Strings::string_to_unsigned_long(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "meleeAttackRange:")) {
        stats.meleeAttackRange = Strings::string_to_long(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "meleeAttackCooldown:")) {
        stats.meleeAttackCooldown = Strings::string_to_unsigned_long(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "meleeAttackPreparation:")) {
        stats.meleeAttackPreparation = Strings::string_to_unsigned_long(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "sightRange:")) {
        stats.sightRange = Strings::string_to_long(line);

        return true;
    } else if (Data_Reader::check_prefix(line, "undead:")) {
        stats.definesUndead = true;
        stats.undead = Strings::string_to_bool(line);

        return true;
    }

    return false;
}

void Game_Data::loadWorld (File_IO_Load* load) {
    String name = "";
    World world;
    vector<string> lines = Data_Reader::read_data(load, "</world>");

    for (size_t i = 0; i < lines.size(); i++) {
        string& line = lines[i];

        if (Data_Reader::check_prefix(line, "name:")) {
            name = line;
        } else if (Data_Reader::check_prefix(line, "deadBecomeRace:")) {
            world.deadBecomeRace = line;
        } else if (Data_Reader::check_prefix(line, "deadBecomeFaction:")) {
            world.deadBecomeFaction = line;
        } else if (Data_Reader::check_prefix(line, "<raceCategory>")) {
            i = loadRaceCategory(lines, i + 1, world);
        } else if (Data_Reader::check_prefix(line, "<faction>")) {
            i = loadFaction(lines, i + 1, world);
        }
    }

    worlds[name] = world;
}

size_t Game_Data::loadRaceCategory (vector<string>& lines, size_t lineIndex, World& world) {
    String name = "";
    RaceCategory raceCategory;

    for (size_t i = lineIndex; i < lines.size(); i++) {
        string& line = lines[i];

        if (!loadStat(line, raceCategory.stats)) {
            if (Data_Reader::check_prefix(line, "name:")) {
                name = line;
            } else if (Data_Reader::check_prefix(line, "</raceCategory>")) {
                world.raceCategories[name] = raceCategory;

                return i;
            }
        }
    }

    world.raceCategories[name] = raceCategory;

    return lines.size() - 1;
}

size_t Game_Data::loadFaction (vector<string>& lines, size_t lineIndex, World& world) {
    String name = "";
    Faction faction;

    for (size_t i = lineIndex; i < lines.size(); i++) {
        string& line = lines[i];

        if (Data_Reader::check_prefix(line, "name:")) {
            name = line;
        } else if (Data_Reader::check_prefix(line, "</faction>")) {
            world.factions[name] = faction;

            return i;
        } else {
            vector<string> data;
            boost::algorithm::split(data, line, boost::algorithm::is_any_of(":"));

            if (data.size() == 2) {
                faction.addRelationship(data[0], Relationship(data[1]));
            }
        }
    }

    world.factions[name] = faction;

    return lines.size() - 1;
}

const World& Game_Data::getWorld (const String& name) {
    if (worlds.count(name)) {
        return worlds[name];
    } else {
        Log::add_error("Error accessing world '" + name + "'");
        Engine::quit();
    }
}

const RaceCategory& Game_Data::getRaceCategory (const String& worldName, const String& name) {
    const World& world = getWorld(worldName);

    if (world.raceCategories.count(name)) {
        return world.raceCategories.at(name);
    } else {
        Log::add_error("Error accessing race category '" + name + "' for world '" + worldName + "'");
        Engine::quit();
    }
}

const Faction& Game_Data::getFaction (const String& worldName, const String& name) {
    const World& world = getWorld(worldName);

    if (world.factions.count(name)) {
        return world.factions.at(name);
    } else {
        Log::add_error("Error accessing faction '" + name + "' for world '" + worldName + "'");
        Engine::quit();
    }
}

void Game_Data::loadRace (File_IO_Load* load) {
    String name = "";
    Race race;
    vector<string> lines = Data_Reader::read_data(load, "</race>");

    for (size_t i = 0; i < lines.size(); i++) {
        string& line = lines[i];

        if (!loadStat(line, race.stats)) {
            if (Data_Reader::check_prefix(line, "name:")) {
                name = line;
            } else if (Data_Reader::check_prefix(line, "category:")) {
                race.category = line;
            } else if (Data_Reader::check_prefix(line, "sprite:")) {
                race.sprite = line;
            } else if (Data_Reader::check_prefix(line, "collisionReduction:")) {
                race.collisionReduction = Strings::string_to_double(line);
            }
        }
    }

    races[name] = race;
}

const Race& Game_Data::getRace (const String& name) {
    if (races.count(name)) {
        return races[name];
    } else {
        Log::add_error("Error accessing race '" + name + "'");
        Engine::quit();
    }
}
