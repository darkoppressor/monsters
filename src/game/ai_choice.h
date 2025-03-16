/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef ai_choice_h
#define ai_choice_h

#include "base_types.h"
#include "ai_goal.h"

class AiChoice {
    private:
        AiGoal::Type goalType;
        int32 priority;

    public:
        AiChoice (AiGoal::Type goalType, int32 priority);
        // Implemented for compatibility with Sorting::quick_sort
        bool operator<= (const AiChoice& choice) const;
        AiGoal::Type getGoalType() const;
};

#endif
