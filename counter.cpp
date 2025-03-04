/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#include "counter.h"

using namespace std;

Counter::Counter () {
    count = 0u;
    counting = false;
}
Counter::Counter (const uint16 count) {
    this->count = count;
    counting = false;
}
uint16 Counter::getCount () const {
    return count;
}
bool Counter::isCounting () const {
    return counting;
}

void Counter::start (const uint16 count) {
    this->count = count;
    counting = true;
}
void Counter::stop () {
    count = 0u;
    counting = false;
}
bool Counter::countdown () {
    if (count > 0) {
        return --count == 0;
    } else {
        return false;
    }
}
