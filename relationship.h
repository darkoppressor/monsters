/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

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
