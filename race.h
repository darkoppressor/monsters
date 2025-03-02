/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
