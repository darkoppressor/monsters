/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "ai_goal.h"
#include "game.h"

using namespace std;

AiGoal::AiGoal () {
    setNone();
}
AiGoal::Type AiGoal::getType () const {
    return type;
}
Index AiGoal::getTargetIndex () const {
    return targetIndex;
}

void AiGoal::setNone () {
    type = Type::none;
    targetIndex = 0;
}
void AiGoal::setUseHealingItem () {
    type = Type::useHealingItem;
    targetIndex = 0;
}
void AiGoal::setAttackCreatureMelee (const Index targetIndex) {
    type = Type::attackCreatureMelee;
    this->targetIndex = targetIndex;
}
void AiGoal::setGetItem (const Index targetIndex) {
    type = Type::getItem;
    this->targetIndex = targetIndex;
}

String AiGoal::getTypeString () const {
    if (type == Type::useHealingItem) {
        return "useHealingItem";
    } else if (type == Type::attackCreatureMelee) {
        return "attackCreatureMelee";
    } else if (type == Type::getItem) {
        return "getItem";
    } else {
        return "none";
    }
}
bool AiGoal::exists () const {
    return type != Type::none;
}
void AiGoal::handleCreatureDeath (const Index index) {
    if (type == Type::attackCreatureMelee && index == targetIndex) {
        setNone();
    }
}
bool AiGoal::isValid (const ConsumableManager& consumables) const {
    if (type == Type::useHealingItem) {
        return consumables.hasHealingItem();
    } else if (type == Type::attackCreatureMelee) {
        return Game::getCreature(targetIndex).isAlive();
    } else if (type == Type::getItem) {
        return Game::getItem(targetIndex).exists();
    } else {
        return false;
    }
}
PixelCoords AiGoal::getTargetPosition () const {
    if (type == Type::attackCreatureMelee) {
        return Game::getCreature(targetIndex).getPosition();
    } else if (type == Type::getItem) {
        return Game::getItem(targetIndex).getPosition();
    } else {
        return PixelCoords();
    }
}
