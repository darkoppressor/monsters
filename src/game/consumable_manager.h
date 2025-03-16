/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
