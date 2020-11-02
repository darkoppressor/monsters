/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef need_h
#define need_h

#include "base_types.h"

class Need {
    public:
        enum class Threshold : uint8 {
            great,
            good,
            ok,
            bad,
            terrible
        };

        static Threshold getThreshold(const Health need, const Health maximumNeed);
};

#endif
