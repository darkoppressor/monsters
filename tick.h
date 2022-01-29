/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
