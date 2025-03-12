/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef item_h
#define item_h

#include "physics_object.h"
#include "base_types.h"

class Item: public PhysicsObject {
    private:
        String type;
        bool equipment;
        bool collected;

    public:
        Item (const TileCoords& position, const String& type, const bool equipment);
        String getType() const;
        bool isEquipment() const;
        bool exists() const;
        void collect();
};

#endif
