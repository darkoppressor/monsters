/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
