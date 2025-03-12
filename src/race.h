/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef race_h
#define race_h

#include "base_types.h"
#include "stats.h"

class Race {
    public:
        String category;
        String sprite;
        // pixels
        Pixels collisionReduction;
        Stats stats;

        Race ();
};

#endif
