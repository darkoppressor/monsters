/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef consumable_type_h
#define consumable_type_h

#include "base_types.h"

class ConsumableType {
    public:
        String displayName;
        String sprite;
        Items maximum;
        Health health;
        Health food;
        Health water;

        ConsumableType ();
};

#endif
