/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "physics_object.h"
#include "game_constants.h"
#include "game.h"

#include <game_manager.h>
#include <engine.h>

using namespace std;

PixelBox PhysicsObject::getCollisionBox (double collisionReduction) const {
    return PixelBox(position.x + collisionReduction, position.y + collisionReduction,
                    sprite.get_width() - collisionReduction * 2.0, sprite.get_height() - collisionReduction * 2.0);
}

PhysicsObject::PhysicsObject (const TileCoords& position, const String& sprite) {
    this->sprite.set_name(sprite);
    this->position = PixelCoords(
        position.x * Game_Constants::TILE_SIZE + Game_Constants::TILE_SIZE / 2.0 - this->sprite.get_width() / 2.0,
        position.y * Game_Constants::TILE_SIZE + Game_Constants::TILE_SIZE / 2.0 - this->sprite.get_height() / 2.0);
}
PixelCoords PhysicsObject::getPosition () const {
    return position;
}
TileCoords PhysicsObject::getTilePosition () const {
    return TileCoords(position.x / Game_Constants::TILE_SIZE, position.y / Game_Constants::TILE_SIZE);
}
void PhysicsObject::setSprite (const String& sprite) {
    this->sprite.set_name(sprite);
}

PixelBox PhysicsObject::getBox () const {
    return PixelBox(position.x, position.y, sprite.get_width(), sprite.get_height());
}

void PhysicsObject::applyMoveForce (double moveForce, double angle) {
    force += Vector(moveForce, angle);
}
void PhysicsObject::brake (double moveForce, double mass) {
    Vector brakeForce(moveForce * 2.0, velocity.direction + 180.0);

    Math::clamp_angle(brakeForce.direction);

    if (brakeForce.magnitude / mass > velocity.magnitude) {
        brakeForce.magnitude = velocity.magnitude * mass;
    }

    force += brakeForce;
}
void PhysicsObject::accelerate (double mass, double maximumSpeed) {
    acceleration = force / mass;

    velocity += acceleration;

    if (velocity.magnitude > maximumSpeed) {
        velocity.magnitude = maximumSpeed;
    }

    force *= 0.0;
}
void PhysicsObject::movement (uint32 collisionSteps, Pixels collisionReduction) {
    // meters / second
    Vector_Components velocityComponents = velocity.get_components();
    // pixels / frame
    Pixels movementX = velocityComponents.a / Game_Constants::PIXELS_TO_METERS / Engine::UPDATE_RATE;
    // pixels / frame
    Pixels movementY = velocityComponents.b / Game_Constants::PIXELS_TO_METERS / Engine::UPDATE_RATE;

    for (uint32 i = 0; i < collisionSteps; i++) {
        position.x += movementX / collisionSteps;
        position.y += movementY / collisionSteps;

        PixelBox collisionBox = getCollisionBox(collisionReduction);

        if (collisionBox.x < 0.0) {
            position.x = 0.0 - collisionReduction;
        }

        if (collisionBox.y < 0.0) {
            position.y = 0.0 - collisionReduction;
        }

        if (collisionBox.x + collisionBox.w >= Game::getWorldWidth()) {
            position.x = Game::getWorldWidth() - collisionBox.w - 1.0;
        }

        if (collisionBox.y + collisionBox.h >= Game::getWorldHeight()) {
            position.y = Game::getWorldHeight() - collisionBox.h - 1.0;
        }
    }
}

void PhysicsObject::animate () {
    sprite.animate();
}
void PhysicsObject::render () const {
    PixelBox box = getBox();

    if (Collision::check_rect(box * Game_Manager::camera_zoom, Game_Manager::camera)) {
        sprite.render(box.x * Game_Manager::camera_zoom - Game_Manager::camera.x,
                      box.y * Game_Manager::camera_zoom - Game_Manager::camera.y, 1.0, Game_Manager::camera_zoom,
                      Game_Manager::camera_zoom);
    }
}
