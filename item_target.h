/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef item_target_h
#define item_target_h

#include "base_types.h"

class ItemTarget {
    private:
        Index index;
        Pixels distance;

    public:
        ItemTarget (const Index index, const Pixels distance);
        // Implemented for compatibility with Sorting::quick_sort
        bool operator<= (const ItemTarget& target) const;
        Index getIndex() const;
};

#endif
