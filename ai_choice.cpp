/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "ai_choice.h"

using namespace std;

AiChoice::AiChoice (AiGoal::Type goalType, int32 priority) {
    this->goalType = goalType;
    this->priority = priority;
}
bool AiChoice::operator<= (const AiChoice& choice) const {
    return priority <= choice.priority;
}
AiGoal::Type AiChoice::getGoalType () const {
    return goalType;
}
