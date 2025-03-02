/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef ai_goal_h
#define ai_goal_h

#include "base_types.h"
#include "consumable_manager.h"

class AiGoal {
    public:
        enum class Type : uint8 {
            none,
            useHealthItem,
            useFoodItem,
            useWaterItem,
            attackCreatureMelee,
            getItem
        };

    private:
        Type type;
        Index targetIndex;

    public:
        AiGoal ();
        Type getType() const;
        Index getTargetIndex() const;

        void setNone();
        void setUseHealthItem();
        void setUseFoodItem();
        void setUseWaterItem();
        void setAttackCreatureMelee(const Index targetIndex);
        void setGetItem(const Index targetIndex);

        String getTypeString() const;
        bool exists() const;
        void handleCreatureDeath(const Index index);
        void handleCreatureDeletion(const Index index);
        void handleItemCollection(const Index index);
        void handleItemDeletion(const Index index);
        bool isValid(const ConsumableManager& consumables) const;
        PixelCoords getTargetPosition() const;
};

#endif
