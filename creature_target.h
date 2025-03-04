/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
