/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef counter_h
#define counter_h

#include "base_types.h"

class Counter {
    private:
        uint16 count;
        bool counting;

    public:
        Counter ();
        Counter (const uint16 count);
        uint16 getCount() const;
        bool isCounting() const;

        void start(const uint16 count);
        void stop();
        // Returns true if the counter just finished
        bool countdown();
};

#endif
