/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
