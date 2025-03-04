/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
