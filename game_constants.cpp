/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "game_constants.h"

#include <game_constants_loader.h>
#include <engine_strings.h>
#include <engine_data.h>

using namespace std;

/// BEGIN SCRIPT-GENERATED CONSTANT INITIALIZATIONS
double Game_Constants::PIXELS_TO_METERS=0.0;
double Game_Constants::TILE_SIZE=0.0;
uint32_t Game_Constants::AI_GOAL_SELECTION_PERIOD=0;
/// END SCRIPT-GENERATED CONSTANT INITIALIZATIONS

void Game_Constants_Loader::set_game_constant (string name, string value) {
    if (name == "zoom_rate") {
        Engine_Data::ZOOM_RATE = Strings::string_to_double(value);
    } else if (name == "zoom_min") {
        Engine_Data::ZOOM_MIN = Strings::string_to_double(value);
    } else if (name == "zoom_max") {
        Engine_Data::ZOOM_MAX = Strings::string_to_double(value);
    }

    /// BEGIN SCRIPT-GENERATED CONSTANT SETUP
    else if(name=="pixels_to_meters"){
        Game_Constants::PIXELS_TO_METERS=Strings::string_to_double(value);
    }
    else if(name=="tile_size"){
        Game_Constants::TILE_SIZE=Strings::string_to_double(value);
    }
    else if(name=="ai_goal_selection_period"){
        Game_Constants::AI_GOAL_SELECTION_PERIOD=Strings::string_to_unsigned_long(value);
    }
    /// END SCRIPT-GENERATED CONSTANT SETUP
}
