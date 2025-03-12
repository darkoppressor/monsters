/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "calendar.h"
#include "game_constants.h"

using namespace std;

Calendar::Calendar () {
    reset();
}
void Calendar::reset () {
    ticks.start(Game_Constants::TICKS_PER_MINUTE);
    minute = 0u;
    hour = 0u;
    day = 0u;
}
Tick Calendar::tick () {
    if (ticks.countdown()) {
        ticks.start(Game_Constants::TICKS_PER_MINUTE);

        if (++minute == Game_Constants::MINUTES_PER_HOUR) {
            minute = 0u;

            if (++hour == Game_Constants::HOURS_PER_DAY) {
                hour = 0u;
                day++;

                return Tick(Tick::Type::day);
            } else {
                return Tick(Tick::Type::hour);
            }
        } else {
            return Tick(Tick::Type::minute);
        }
    } else {
        return Tick(Tick::Type::none);
    }
}
