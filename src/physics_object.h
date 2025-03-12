/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef physics_object_h
#define physics_object_h

#include "base_types.h"

#include <math_vector.h>
#include <sprite.h>

class PhysicsObject {
    private:
        PixelCoords position;
        // meters / second, degrees
        Vector velocity;
        // meters / second, degrees
        Vector acceleration;
        // newtons, degrees
        Vector force;
        Sprite sprite;

        PixelBox getCollisionBox(double collisionReduction) const;
    public:
        PhysicsObject (const TileCoords& position, const String& sprite);
        PixelCoords getPosition() const;
        TileCoords getTilePosition() const;
        void setSprite(const String& sprite);

        PixelBox getBox() const;

        void applyMoveForce(double moveForce, double angle);
        void brake(double moveForce, double mass);
        void accelerate(double mass, double maximumSpeed);
        void movement(uint32 collisionSteps, Pixels collisionReduction);

        void animate();
        void render() const;
};

#endif
