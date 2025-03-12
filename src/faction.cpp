/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "faction.h"

#include <log.h>
#include <engine.h>

using namespace std;

const Relationship& Faction::getRelationship (const String& faction) const {
    if (relationships.count(faction)) {
        return relationships.at(faction);
    } else {
        Log::add_error("Error accessing relationship to '" + faction + "'");
        Engine::quit();
    }
}
void Faction::addRelationship (const String& key, const Relationship& relationship) {
    relationships.emplace(key, relationship);
}
