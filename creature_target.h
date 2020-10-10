/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef creature_target_h
#define creature_target_h

#include "base_types.h"

class CreatureTarget {
    private:
        Index index;
        Pixels distance;
    public:
        CreatureTarget (const Index index, const Pixels distance);
        // Implemented for compatibility with Sorting::quick_sort
        bool operator<= (const CreatureTarget& target) const;
        Index getIndex() const;
};

#endif
