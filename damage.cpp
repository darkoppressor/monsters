/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "damage.h"
#include "game.h"

using namespace std;

Damage::Damage (const Chance chance, const String& type, const Health amount) {
    this->chance = chance;
    this->type = type;
    this->amount = amount;
}
Health Damage::getAmount () const {
    return amount;
}

bool Damage::damages (const Creature& creature) const {
    return Game::getRng().random_range(0, 99) < chance && Game::getRng().random_range(0,
                                                                                      99) >=
           creature.getDamageAvoidanceChance();
}
Health Damage::getModifiedAmount (const Creature& creature) const {
    if (type == "smashing") {
        return max(amount - creature.getSmashingDefense(), 0);
    } else if (type == "slashing") {
        return max(amount - creature.getSlashingDefense(), 0);
    } else if (type == "stabbing") {
        return max(amount - creature.getStabbingDefense(), 0);
    }
}
