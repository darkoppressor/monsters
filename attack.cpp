/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "attack.h"

using namespace std;

Attack::Attack () {
    inProgress = false;
}
bool Attack::isInProgress () const {
    return inProgress;
}
void Attack::start (const uint16 preparationCount) {
    inProgress = true;
    preparation.start(preparationCount);
}
void Attack::stop () {
    inProgress = false;
    preparation.stop();
}

bool Attack::isCooled () const {
    return !cooldown.isCounting();
}
void Attack::startCooling (const uint16 count) {
    cooldown.start(count);
}
void Attack::stopCooling () {
    cooldown.stop();
}
bool Attack::cool () {
    return cooldown.countdown();
}

bool Attack::prepare () {
    return preparation.countdown();
}

const Counter& Attack::getCooldownCounter () const {
    return cooldown;
}
const Counter& Attack::getPreparationCounter () const {
    return preparation;
}
