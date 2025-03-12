/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef world_h
#define world_h

#include "base_types.h"
#include "race_category.h"
#include "faction.h"
#include "equipment_type.h"
#include "consumable_type.h"

class World {
    public:
        String deadBecomeRace;
        String deadBecomeFaction;
        UnorderedMap<String, RaceCategory> raceCategories;
        UnorderedMap<String, Faction> factions;
        UnorderedMap<String, EquipmentType> equipment;
        UnorderedMap<String, ConsumableType> consumables;

        World ();
};

#endif
