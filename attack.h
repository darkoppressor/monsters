/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
