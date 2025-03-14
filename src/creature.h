/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef creature_h
#define creature_h

#include "physics_object.h"
#include "base_types.h"
#include "ai_goal.h"
#include "attack.h"
#include "relationship.h"
#include "damage.h"
#include "equipment_manager.h"
#include "consumable_manager.h"
#include "creature_target.h"
#include "ai_choice.h"
#include "item_target.h"
#include "item.h"

class Damage;

class Creature: public PhysicsObject {
    private:
        String race;
        String faction;
        Health health;
        Health food;
        Health water;
        AiGoal goal;
        Attack attack;
        EquipmentManager equipment;
        ConsumableManager consumables;

        Pixels getCollisionReduction() const;
        double getMass() const;
        double getMoveForce() const;
        double getMaximumSpeed() const;
        uint32 getCollisionSteps() const;
        Health getHunger() const;
        Health getThirst() const;
        double getMeleeSkill() const;
        Chance getMeleeDamageChance() const;
        String getMeleeAttackDamageType() const;
        Health getMeleeAttackMinimumDamage() const;
        Health getMeleeAttackMaximumDamage() const;
        Tiles getMeleeAttackRange() const;
        Count getMeleeAttackCooldown() const;
        Count getMeleeAttackPreparation() const;
        double getDefenseSkill() const;
        Tiles getGetItemRange() const;
        Tiles getSightRange() const;
        bool isUndead() const;
        bool canGetItems() const;
        bool canUseItems() const;
        bool hungers() const;
        bool thirsts() const;

        double getHealthModifier() const;
        double getFoodModifier() const;
        double getWaterModifier() const;
        const Relationship& getRelationship(const Creature& creature) const;

        void hunger();
        void thirst();
    public:
        Creature (const TileCoords& position, const String& race, const String& faction);
        String getRace() const;
        String getFaction() const;
        Health getHealth() const;
        Health getFood() const;
        Health getWater() const;
        const AiGoal& getGoal() const;
        const Attack& getAttack() const;
        EquipmentManager& getEquipment();
        ConsumableManager& getConsumables();

        Health getMaximumHealth() const;
        Health getMaximumFood() const;
        Health getMaximumWater() const;
        Chance getDamageAvoidanceChance() const;
        Health getSmashingDefense() const;
        Health getSlashingDefense() const;
        Health getStabbingDefense() const;

        bool isAlive() const;
        PixelBox getSight() const;

        void handleCalendarMinute();
        void handleCalendarHour(const Index index);

        void heal(Health health);
        void eat(Health food);
        void drink(Health water);

        void meleeAttack(const Index index, const Index creatureIndex);
        // Returns counterattack damage
        Damage takeMeleeDamage(const Index index, const Damage& damage);
        void takeTypelessDamage(const Index index, const Health damage);
        void die(const Index index);

        void handleCreatureDeath(const Index index);
        void handleCreatureDeletion(const Index index);
        void handleItemCollection(const Index index);
        void handleItemDeletion(const Index index);
        bool canCheckForAiGoal(const Index index) const;
        void considerUsingConsumable(List<AiChoice>& choices);
        List<CreatureTarget> considerAttackingCreature(List<AiChoice>& choices, const Index index);
        bool isItemDesired(const Item& item);
        List<ItemTarget> considerGettingItem(List<AiChoice>& choices);
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
