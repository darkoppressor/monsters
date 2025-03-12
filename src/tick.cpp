/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "tick.h"

using namespace std;

Tick::Tick (const Type type) {
    this->type = type;
}
Tick::Type Tick::getType () const {
    return type;
}
