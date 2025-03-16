/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "item_target.h"

using namespace std;

ItemTarget::ItemTarget (const Index index, const Pixels distance) {
    this->index = index;
    this->distance = distance;
}
bool ItemTarget::operator<= (const ItemTarget& target) const {
    return distance > target.distance;
}
Index ItemTarget::getIndex () const {
    return index;
}
