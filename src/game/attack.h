/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef attack_h
#define attack_h

#include "counter.h"

class Attack {
    private:
        bool inProgress;
        Counter cooldown;
        Counter preparation;

    public:
        Attack ();
        bool isInProgress() const;
        void start(const uint16 preparationCount);
        void stop();

        bool isCooled() const;
        void startCooling(const uint16 count);
        void stopCooling();
        bool cool();

        bool prepare();

        const Counter& getCooldownCounter() const;
        const Counter& getPreparationCounter() const;
};

#endif
