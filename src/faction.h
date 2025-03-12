/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
