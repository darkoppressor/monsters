/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef relationship_h
#define relationship_h

#include "base_types.h"

class Relationship {
    public:
        enum class Type : uint8 {
            friendly,
            hostile
        };

    private:
        Type type;

    public:
        Relationship ();
        Relationship (const String& type);
        Type getType() const;
};

#endif
