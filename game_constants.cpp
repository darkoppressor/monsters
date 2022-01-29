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
uint16_t Game_Constants::TICKS_PER_MINUTE=0;
uint16_t Game_Constants::MINUTES_PER_HOUR=0;
uint16_t Game_Constants::HOURS_PER_DAY=0;
uint32_t Game_Constants::MAXIMUM_DEAD_BODIES=0;
double Game_Constants::NEED_THRESHOLD_GREAT=0.0;
double Game_Constants::NEED_THRESHOLD_GOOD=0.0;
double Game_Constants::NEED_THRESHOLD_OK=0.0;
double Game_Constants::NEED_THRESHOLD_BAD=0.0;
double Game_Constants::HEALTH_MODIFIER_GREAT=0.0;
double Game_Constants::HEALTH_MODIFIER_GOOD=0.0;
double Game_Constants::HEALTH_MODIFIER_OK=0.0;
double Game_Constants::HEALTH_MODIFIER_BAD=0.0;
double Game_Constants::HEALTH_MODIFIER_TERRIBLE=0.0;
double Game_Constants::FOOD_MODIFIER_GREAT=0.0;
double Game_Constants::FOOD_MODIFIER_GOOD=0.0;
double Game_Constants::FOOD_MODIFIER_OK=0.0;
double Game_Constants::FOOD_MODIFIER_BAD=0.0;
double Game_Constants::FOOD_MODIFIER_TERRIBLE=0.0;
double Game_Constants::FOOD_HEALTH_LOSS=0.0;
double Game_Constants::WATER_MODIFIER_GREAT=0.0;
double Game_Constants::WATER_MODIFIER_GOOD=0.0;
double Game_Constants::WATER_MODIFIER_OK=0.0;
double Game_Constants::WATER_MODIFIER_BAD=0.0;
double Game_Constants::WATER_MODIFIER_TERRIBLE=0.0;
double Game_Constants::WATER_HEALTH_LOSS=0.0;
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
    else if(name=="ticks_per_minute"){
        Game_Constants::TICKS_PER_MINUTE=Strings::string_to_unsigned_long(value);
    }
    else if(name=="minutes_per_hour"){
        Game_Constants::MINUTES_PER_HOUR=Strings::string_to_unsigned_long(value);
    }
    else if(name=="hours_per_day"){
        Game_Constants::HOURS_PER_DAY=Strings::string_to_unsigned_long(value);
    }
    else if(name=="maximum_dead_bodies"){
        Game_Constants::MAXIMUM_DEAD_BODIES=Strings::string_to_unsigned_long(value);
    }
    else if(name=="need_threshold_great"){
        Game_Constants::NEED_THRESHOLD_GREAT=Strings::string_to_double(value);
    }
    else if(name=="need_threshold_good"){
        Game_Constants::NEED_THRESHOLD_GOOD=Strings::string_to_double(value);
    }
    else if(name=="need_threshold_ok"){
        Game_Constants::NEED_THRESHOLD_OK=Strings::string_to_double(value);
    }
    else if(name=="need_threshold_bad"){
        Game_Constants::NEED_THRESHOLD_BAD=Strings::string_to_double(value);
    }
    else if(name=="health_modifier_great"){
        Game_Constants::HEALTH_MODIFIER_GREAT=Strings::string_to_double(value);
    }
    else if(name=="health_modifier_good"){
        Game_Constants::HEALTH_MODIFIER_GOOD=Strings::string_to_double(value);
    }
    else if(name=="health_modifier_ok"){
        Game_Constants::HEALTH_MODIFIER_OK=Strings::string_to_double(value);
    }
    else if(name=="health_modifier_bad"){
        Game_Constants::HEALTH_MODIFIER_BAD=Strings::string_to_double(value);
    }
    else if(name=="health_modifier_terrible"){
        Game_Constants::HEALTH_MODIFIER_TERRIBLE=Strings::string_to_double(value);
    }
    else if(name=="food_modifier_great"){
        Game_Constants::FOOD_MODIFIER_GREAT=Strings::string_to_double(value);
    }
    else if(name=="food_modifier_good"){
        Game_Constants::FOOD_MODIFIER_GOOD=Strings::string_to_double(value);
    }
    else if(name=="food_modifier_ok"){
        Game_Constants::FOOD_MODIFIER_OK=Strings::string_to_double(value);
    }
    else if(name=="food_modifier_bad"){
        Game_Constants::FOOD_MODIFIER_BAD=Strings::string_to_double(value);
    }
    else if(name=="food_modifier_terrible"){
        Game_Constants::FOOD_MODIFIER_TERRIBLE=Strings::string_to_double(value);
    }
    else if(name=="food_health_loss"){
        Game_Constants::FOOD_HEALTH_LOSS=Strings::string_to_double(value);
    }
    else if(name=="water_modifier_great"){
        Game_Constants::WATER_MODIFIER_GREAT=Strings::string_to_double(value);
    }
    else if(name=="water_modifier_good"){
        Game_Constants::WATER_MODIFIER_GOOD=Strings::string_to_double(value);
    }
    else if(name=="water_modifier_ok"){
        Game_Constants::WATER_MODIFIER_OK=Strings::string_to_double(value);
    }
    else if(name=="water_modifier_bad"){
        Game_Constants::WATER_MODIFIER_BAD=Strings::string_to_double(value);
    }
    else if(name=="water_modifier_terrible"){
        Game_Constants::WATER_MODIFIER_TERRIBLE=Strings::string_to_double(value);
    }
    else if(name=="water_health_loss"){
        Game_Constants::WATER_HEALTH_LOSS=Strings::string_to_double(value);
    }
    /// END SCRIPT-GENERATED CONSTANT SETUP
}
