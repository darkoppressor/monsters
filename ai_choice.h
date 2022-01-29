/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
