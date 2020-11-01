/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "tick.h"

using namespace std;

Tick::Tick (const Type type) {
    this->type = type;
}
Tick::Type Tick::getType () const {
    return type;
}
