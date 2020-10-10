/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef faction_h
#define faction_h

#include "base_types.h"
#include "relationship.h"

class Faction {
    private:
        UnorderedMap<String, Relationship> relationships;
    public:
        const Relationship& getRelationship(const String& faction) const;
        void addRelationship(const String& key, const Relationship& relationship);
};

#endif
