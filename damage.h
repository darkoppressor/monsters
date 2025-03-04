/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef damage_h
#define damage_h

#include "base_types.h"
#include "creature.h"

class Creature;

class Damage {
    private:
        Chance chance;
        String type;
        Health amount;

    public:
        Damage (const Chance chance, const String& type, const Health amount);
        Health getAmount() const;

        bool damages(const Creature& creature) const;
        Health getModifiedAmount(const Creature& creature) const;
};

#endif
