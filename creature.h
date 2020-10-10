/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef creature_h
#define creature_h

#include "physics_object.h"
#include "base_types.h"
#include "ai_goal.h"
#include "attack.h"
#include "relationship.h"

class Creature: public PhysicsObject {
    private:
        String race;
        String faction;
        Health health;
        AiGoal goal;
        Attack attack;

        Pixels getCollisionReduction() const;
        double getMass() const;
        double getMoveForce() const;
        double getMaximumSpeed() const;
        uint32 getCollisionSteps() const;
        String getMeleeAttackDamageType() const;
        Health getMeleeAttackMinimumDamage() const;
        Health getMeleeAttackMaximumDamage() const;
        Tiles getMeleeAttackRange() const;
        Count getMeleeAttackCooldown() const;
        Count getMeleeAttackPreparation() const;
        Tiles getSightRange() const;
        bool isUndead() const;

        const Relationship& getRelationship(const Creature& creature) const;
    public:
        Creature (const TileCoords& position, const String& race, const String& faction);
        String getRace() const;
        String getFaction() const;
        Health getHealth() const;
        AiGoal getGoal() const;
        Attack getAttack() const;

        Health getMaximumHealth() const;

        bool isAlive() const;
        PixelBox getSight() const;

        void meleeAttack(const Index index, const Index creatureIndex);
        // Returns counterattack damage
        Health takeDamage(const Index index, const Health damage);
        void die(const Index index);

        void handleCreatureDeath(const Index index);
        bool canCheckForAiGoal(const Index index) const;
        void think(const Index index);
        void act(const Index index);
        void doNothing();
        void startMeleeAttack();
        void continueMeleeAttack(const Index index);

        void applyMoveForce(double angle);
        void brake();
        void accelerate();
        void movement();
};

#endif
