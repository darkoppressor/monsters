/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "ai_goal.h"
#include "game.h"

using namespace std;

AiGoal::AiGoal () {
    setNone();
}
String AiGoal::getType () const {
    if (type == Type::attackCreatureMelee) {
        return "attackCreatureMelee";
    } else {
        return "none";
    }
}
Index AiGoal::getTargetIndex () const {
    return targetIndex;
}

void AiGoal::setNone () {
    type = Type::none;
    targetIndex = 0;
}
void AiGoal::setAttackCreatureMelee (const Index targetIndex) {
    type = Type::attackCreatureMelee;
    this->targetIndex = targetIndex;
}

bool AiGoal::exists () const {
    return type != Type::none;
}
void AiGoal::handleCreatureDeath (const Index index) {
    if (type == Type::attackCreatureMelee && index == targetIndex) {
        setNone();
    }
}
bool AiGoal::isValid () const {
    if (type == Type::attackCreatureMelee) {
        return Game::getCreature(targetIndex).isAlive();
    } else {
        return false;
    }
}
PixelCoords AiGoal::getTargetPosition () const {
    if (type == Type::attackCreatureMelee) {
        return Game::getCreature(targetIndex).getPosition();
    } else {
        return PixelCoords();
    }
}
