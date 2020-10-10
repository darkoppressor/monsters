/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef world_h
#define world_h

#include "base_types.h"
#include "race_category.h"
#include "faction.h"
#include "equipment_type.h"

class World {
    public:
        String deadBecomeRace;
        String deadBecomeFaction;
        UnorderedMap<String, RaceCategory> raceCategories;
        UnorderedMap<String, Faction> factions;
        UnorderedMap<String, EquipmentType> equipment;

        World ();
};

#endif
