/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
