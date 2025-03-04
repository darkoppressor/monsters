/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef game_constants_h
#define game_constants_h

#include <string>
#include <cstdint>

class Game_Constants {
    public:
        // BEGIN SCRIPT-GENERATED CONSTANT DECLARATIONS
        static double PIXELS_TO_METERS;
        static double TILE_SIZE;
        static std::uint32_t AI_GOAL_SELECTION_PERIOD;
        static std::uint16_t TICKS_PER_MINUTE;
        static std::uint16_t MINUTES_PER_HOUR;
        static std::uint16_t HOURS_PER_DAY;
        static std::uint32_t MAXIMUM_DEAD_BODIES;
        static double NEED_THRESHOLD_GREAT;
        static double NEED_THRESHOLD_GOOD;
        static double NEED_THRESHOLD_OK;
        static double NEED_THRESHOLD_BAD;
        static double HEALTH_MODIFIER_GREAT;
        static double HEALTH_MODIFIER_GOOD;
        static double HEALTH_MODIFIER_OK;
        static double HEALTH_MODIFIER_BAD;
        static double HEALTH_MODIFIER_TERRIBLE;
        static double FOOD_MODIFIER_GREAT;
        static double FOOD_MODIFIER_GOOD;
        static double FOOD_MODIFIER_OK;
        static double FOOD_MODIFIER_BAD;
        static double FOOD_MODIFIER_TERRIBLE;
        static double FOOD_HEALTH_LOSS;
        static double WATER_MODIFIER_GREAT;
        static double WATER_MODIFIER_GOOD;
        static double WATER_MODIFIER_OK;
        static double WATER_MODIFIER_BAD;
        static double WATER_MODIFIER_TERRIBLE;
        static double WATER_HEALTH_LOSS;
        // END SCRIPT-GENERATED CONSTANT DECLARATIONS
};

#endif
