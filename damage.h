/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef damage_h
#define damage_h

#include "base_types.h"
#include "creature.h"

class Creature;

class Damage {
    private:
        String type;
        Health amount;
    public:
        Damage (const String& type, const Health amount);
        Health getAmount() const;

        Health getModifiedAmount(const Creature& creature) const;
};

#endif
