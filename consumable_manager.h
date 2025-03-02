/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef consumable_manager_h
#define consumable_manager_h

#include "base_types.h"
#include "consumable_type.h"

class ConsumableManager {
    private:
        UnorderedMap<String, Items> consumables;

    public:
        void add(const String& item, const TileCoords& position);

        List<String> getKeys() const;
        Items getItemCount(const String& item) const;

        bool canHold(const String& item) const;

        bool hasHealthItem() const;
        Health useHealthItem();
        bool hasFoodItem() const;
        Health useFoodItem();
        bool hasWaterItem() const;
        Health useWaterItem();
};

#endif
