/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
