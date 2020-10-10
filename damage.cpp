/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "damage.h"

using namespace std;

Damage::Damage (const String& type, const Health amount) {
    this->type = type;
    this->amount = amount;
}
Health Damage::getAmount () const {
    return amount;
}

Health Damage::getModifiedAmount (const Creature& creature) const {
    if (type == "smashing") {
        return max(amount - creature.getSmashingResistance(), 0);
    } else if (type == "slashing") {
        return max(amount - creature.getSlashingResistance(), 0);
    } else if (type == "stabbing") {
        return max(amount - creature.getStabbingResistance(), 0);
    }
}
