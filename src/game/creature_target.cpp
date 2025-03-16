/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
