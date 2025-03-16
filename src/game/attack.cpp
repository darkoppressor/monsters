/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
