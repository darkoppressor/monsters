/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef ai_goal_h
#define ai_goal_h

#include "base_types.h"

class AiGoal {
    public:
        enum class Type : uint8 {
            none,
            attackCreatureMelee
        };
    private:
        Type type;
        Index targetIndex;
    public:
        AiGoal ();
        String getType() const;
        Index getTargetIndex() const;

        void setNone();
        void setAttackCreatureMelee(const Index targetIndex);

        bool exists() const;
        void handleCreatureDeath(const Index index);
        bool isValid() const;
        PixelCoords getTargetPosition() const;
};

#endif
