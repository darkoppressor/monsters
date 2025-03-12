/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef calendar_h
#define calendar_h

#include "counter.h"
#include "base_types.h"
#include "tick.h"

class Calendar {
    private:
        Counter ticks;
        uint16 minute;
        uint16 hour;
        uint16 day;

    public:
        Calendar ();
        void reset();
        Tick tick();
};

#endif
