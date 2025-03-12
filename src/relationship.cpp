/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "relationship.h"

using namespace std;

Relationship::Relationship () {
    type = Type::friendly;
}
Relationship::Relationship (const String& type) {
    if (type == "friendly") {
        this->type = Type::friendly;
    } else if (type == "hostile") {
        this->type = Type::hostile;
    }
}
Relationship::Type Relationship::getType () const {
    return type;
}
