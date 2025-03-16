/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef tick_h
#define tick_h

#include "base_types.h"

class Tick {
    public:
        enum class Type : uint8 {
            none,
            minute,
            hour,
            day
        };

    private:
        Type type;

    public:
        Tick (const Type type);
        Type getType() const;
};

#endif
