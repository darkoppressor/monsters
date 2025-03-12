/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

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
