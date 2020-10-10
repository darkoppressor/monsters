/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
