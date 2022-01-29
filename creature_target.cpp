/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "creature_target.h"

using namespace std;

CreatureTarget::CreatureTarget (const Index index, const Pixels distance) {
    this->index = index;
    this->distance = distance;
}
bool CreatureTarget::operator<= (const CreatureTarget& target) const {
    return distance > target.distance;
}
Index CreatureTarget::getIndex () const {
    return index;
}
