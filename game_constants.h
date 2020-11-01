/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef game_constants_h
#define game_constants_h

#include <string>
#include <cstdint>

class Game_Constants {
    public:
    /// BEGIN SCRIPT-GENERATED CONSTANT DECLARATIONS
    static double PIXELS_TO_METERS;
    static double TILE_SIZE;
    static std::uint32_t AI_GOAL_SELECTION_PERIOD;
    static std::uint16_t TICKS_PER_MINUTE;
    static std::uint16_t MINUTES_PER_HOUR;
    static std::uint16_t HOURS_PER_DAY;
    static std::uint32_t MAXIMUM_DEAD_BODIES;
    /// END SCRIPT-GENERATED CONSTANT DECLARATIONS
};

#endif
