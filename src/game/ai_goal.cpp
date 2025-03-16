/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
void AiGoal::setUseHealthItem () {
    type = Type::useHealthItem;
    targetIndex = 0;
}
void AiGoal::setUseFoodItem () {
    type = Type::useFoodItem;
    targetIndex = 0;
}
void AiGoal::setUseWaterItem () {
    type = Type::useWaterItem;
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
    if (type == Type::useHealthItem) {
        return "useHealthItem";
    } else if (type == Type::useFoodItem) {
        return "useFoodItem";
    } else if (type == Type::useWaterItem) {
        return "useWaterItem";
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
void AiGoal::handleCreatureDeletion (const Index index) {
    if (type == Type::attackCreatureMelee && targetIndex > index) {
        targetIndex--;
    }
}
void AiGoal::handleItemCollection (const Index index) {
    if (type == Type::getItem && index == targetIndex) {
        setNone();
    }
}
void AiGoal::handleItemDeletion (const Index index) {
    if (type == Type::getItem && targetIndex > index) {
        targetIndex--;
    }
}
bool AiGoal::isValid (const ConsumableManager& consumables) const {
    if (type == Type::useHealthItem) {
        return consumables.hasHealthItem();
    } else if (type == Type::useFoodItem) {
        return consumables.hasFoodItem();
    } else if (type == Type::useWaterItem) {
        return consumables.hasWaterItem();
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
