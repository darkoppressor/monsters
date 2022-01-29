/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
