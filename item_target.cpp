/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
