/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "creature.h"
#include "game_data.h"
#include "game.h"
#include "game_constants.h"
#include "need.h"

using namespace std;

Pixels Creature::getCollisionReduction () const {
    return Game_Data::getRace(race).collisionReduction;
}
double Creature::getMass () const {
    double mass = 0.0;

    mass += equipment.getMass();

    const Race& race = Game_Data::getRace(this->race);

    mass += race.stats.mass != Stats::NO_MASS ? race.stats.mass : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.mass;

    return mass;
}
double Creature::getMoveForce () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.moveForce !=
           Stats::NO_MOVE_FORCE ? race.stats.moveForce * getHealthModifier() : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.moveForce * getHealthModifier();
}
double Creature::getMaximumSpeed () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.maximumSpeed !=
           Stats::NO_MAXIMUM_SPEED ? race.stats.maximumSpeed * getHealthModifier() : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.maximumSpeed * getHealthModifier();
}
uint32 Creature::getCollisionSteps () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.collisionSteps !=
           Stats::NO_COLLISION_STEPS ? race.stats.collisionSteps : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.collisionSteps;
}
Health Creature::getHunger () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.hunger != Stats::NO_HUNGER ? race.stats.hunger : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.hunger;
}
Health Creature::getThirst () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.thirst != Stats::NO_THIRST ? race.stats.thirst : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.thirst;
}
double Creature::getMeleeSkill () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeSkill !=
           Stats::NO_MELEE_SKILL ? race.stats.meleeSkill * getWaterModifier() : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeSkill * getWaterModifier();
}
Chance Creature::getMeleeDamageChance () const {
    if (equipment.hasMeleeWeapon()) {
        return equipment.getMeleeWeapon().damageChance * getMeleeSkill();
    }

    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeDamageChance !=
           Stats::NO_MELEE_DAMAGE_CHANCE ? race.stats.meleeDamageChance * getMeleeSkill() : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeDamageChance * getMeleeSkill();
}
String Creature::getMeleeAttackDamageType () const {
    if (equipment.hasMeleeWeapon()) {
        return equipment.getMeleeWeapon().damageType;
    }

    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackDamageType !=
           Stats::NO_MELEE_ATTACK_DAMAGE_TYPE ? race.stats.meleeAttackDamageType : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackDamageType;
}
Health Creature::getMeleeAttackMinimumDamage () const {
    Health minimumDamage = 0;

    if (equipment.hasMeleeWeapon()) {
        minimumDamage += equipment.getMeleeWeapon().minimumDamage;
    }

    const Race& race = Game_Data::getRace(this->race);

    minimumDamage += race.stats.meleeAttackMinimumDamage !=
                     Stats::NO_MELEE_ATTACK_MINIMUM_DAMAGE ? race.stats.meleeAttackMinimumDamage : Game_Data::
                     getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackMinimumDamage;

    return minimumDamage;
}
Health Creature::getMeleeAttackMaximumDamage () const {
    Health maximumDamage = 0;

    if (equipment.hasMeleeWeapon()) {
        maximumDamage += equipment.getMeleeWeapon().maximumDamage;
    }

    const Race& race = Game_Data::getRace(this->race);

    maximumDamage += race.stats.meleeAttackMaximumDamage !=
                     Stats::NO_MELEE_ATTACK_MAXIMUM_DAMAGE ? race.stats.meleeAttackMaximumDamage : Game_Data::
                     getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackMaximumDamage;

    return maximumDamage;
}
Tiles Creature::getMeleeAttackRange () const {
    if (equipment.hasMeleeWeapon()) {
        return equipment.getMeleeWeapon().range;
    }

    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackRange !=
           Stats::NO_MELEE_ATTACK_RANGE ? race.stats.meleeAttackRange : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackRange;
}
Count Creature::getMeleeAttackCooldown () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackCooldown !=
           Stats::NO_MELEE_ATTACK_COOLDOWN ? race.stats.meleeAttackCooldown : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackCooldown;
}
Count Creature::getMeleeAttackPreparation () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.meleeAttackPreparation !=
           Stats::NO_MELEE_ATTACK_PREPARATION ? race.stats.meleeAttackPreparation : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.meleeAttackPreparation;
}
double Creature::getDefenseSkill () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.defenseSkill !=
           Stats::NO_DEFENSE_SKILL ? race.stats.defenseSkill * getWaterModifier() : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.defenseSkill * getWaterModifier();
}
Tiles Creature::getGetItemRange () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.getItemRange != Stats::NO_GET_ITEM_RANGE ? race.stats.getItemRange : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.getItemRange;
}
Tiles Creature::getSightRange () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.sightRange != Stats::NO_SIGHT_RANGE ? race.stats.sightRange : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.sightRange;
}
bool Creature::isUndead () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.definesUndead ? race.stats.undead : Game_Data::getRaceCategory(Game::getWorldName(),
                                                                                     race.category).stats.undead;
}
bool Creature::canGetItems () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.definesCanGetItems ? race.stats.canGetItems : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.canGetItems;
}
bool Creature::canUseItems () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.definesCanUseItems ? race.stats.canUseItems : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.canUseItems;
}
bool Creature::hungers () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.definesHungers ? race.stats.hungers : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.hungers;
}
bool Creature::thirsts () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.definesThirsts ? race.stats.thirsts : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.thirsts;
}

double Creature::getHealthModifier () const {
    Need::Threshold threshold = Need::getThreshold(health, getMaximumHealth());

    if (threshold == Need::Threshold::great) {
        return Game_Constants::HEALTH_MODIFIER_GREAT;
    } else if (threshold == Need::Threshold::good) {
        return Game_Constants::HEALTH_MODIFIER_GOOD;
    } else if (threshold == Need::Threshold::ok) {
        return Game_Constants::HEALTH_MODIFIER_OK;
    } else if (threshold == Need::Threshold::bad) {
        return Game_Constants::HEALTH_MODIFIER_BAD;
    } else if (threshold == Need::Threshold::terrible) {
        return Game_Constants::HEALTH_MODIFIER_TERRIBLE;
    } else {
        return 0.0;
    }
}
double Creature::getFoodModifier () const {
    if (hungers()) {
        Need::Threshold threshold = Need::getThreshold(food, getMaximumFood());

        if (threshold == Need::Threshold::great) {
            return Game_Constants::FOOD_MODIFIER_GREAT;
        } else if (threshold == Need::Threshold::good) {
            return Game_Constants::FOOD_MODIFIER_GOOD;
        } else if (threshold == Need::Threshold::ok) {
            return Game_Constants::FOOD_MODIFIER_OK;
        } else if (threshold == Need::Threshold::bad) {
            return Game_Constants::FOOD_MODIFIER_BAD;
        } else if (threshold == Need::Threshold::terrible) {
            return Game_Constants::FOOD_MODIFIER_TERRIBLE;
        } else {
            return 0.0;
        }
    } else {
        return Game_Constants::FOOD_MODIFIER_GREAT;
    }
}
double Creature::getWaterModifier () const {
    if (thirsts()) {
        Need::Threshold threshold = Need::getThreshold(water, getMaximumWater());

        if (threshold == Need::Threshold::great) {
            return Game_Constants::WATER_MODIFIER_GREAT;
        } else if (threshold == Need::Threshold::good) {
            return Game_Constants::WATER_MODIFIER_GOOD;
        } else if (threshold == Need::Threshold::ok) {
            return Game_Constants::WATER_MODIFIER_OK;
        } else if (threshold == Need::Threshold::bad) {
            return Game_Constants::WATER_MODIFIER_BAD;
        } else if (threshold == Need::Threshold::terrible) {
            return Game_Constants::WATER_MODIFIER_TERRIBLE;
        } else {
            return 0.0;
        }
    } else {
        return Game_Constants::WATER_MODIFIER_GREAT;
    }
}
const Relationship& Creature::getRelationship (const Creature& creature) const {
    return Game_Data::getFaction(Game::getWorldName(), this->faction).getRelationship(creature.getFaction());
}

void Creature::hunger () {
    if (isAlive() && hungers()) {
        if (getHunger() >= food) {
            food = 0;
        } else {
            food -= getHunger();
        }

        if (health > getMaximumHealth()) {
            health = getMaximumHealth();
        }
    }
}
void Creature::thirst () {
    if (isAlive() && thirsts()) {
        if (getThirst() >= water) {
            water = 0;
        } else {
            water -= getThirst();
        }
    }
}

Creature::Creature (const TileCoords& position, const String& race, const String& faction):PhysicsObject(position, Game_Data::getRace(
                                                                                                             race).sprite)
{
    this->race = race;
    this->faction = faction;
    food = getMaximumFood();
    water = getMaximumWater();
    health = getMaximumHealth();
}
String Creature::getRace () const {
    return race;
}
String Creature::getFaction () const {
    return faction;
}
Health Creature::getHealth () const {
    return health;
}
Health Creature::getFood () const {
    return food;
}
Health Creature::getWater () const {
    return water;
}
const AiGoal& Creature::getGoal () const {
    return goal;
}
const Attack& Creature::getAttack () const {
    return attack;
}
EquipmentManager& Creature::getEquipment () {
    return equipment;
}
ConsumableManager& Creature::getConsumables () {
    return consumables;
}

Health Creature::getMaximumHealth () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.maximumHealth !=
           Stats::NO_MAXIMUM_HEALTH ? race.stats.maximumHealth * getFoodModifier() : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.maximumHealth * getFoodModifier();
}
Health Creature::getMaximumFood () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.maximumFood != Stats::NO_MAXIMUM_FOOD ? race.stats.maximumFood : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.maximumFood;
}
Health Creature::getMaximumWater () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.maximumWater != Stats::NO_MAXIMUM_WATER ? race.stats.maximumWater : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.maximumWater;
}
Chance Creature::getDamageAvoidanceChance () const {
    // QQQ Handle equipped armor
    // Probably add the base value to the sum of all armor
    // Actually probably do an average

    const Race& race = Game_Data::getRace(this->race);

    return race.stats.damageAvoidanceChance !=
           Stats::NO_DAMAGE_AVOIDANCE_CHANCE ? race.stats.damageAvoidanceChance *
           getDefenseSkill() : Game_Data::getRaceCategory(Game::getWorldName(),
                                                          race.category).stats.damageAvoidanceChance *
           getDefenseSkill();
}
Health Creature::getSmashingDefense () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.smashingDefense !=
           Stats::NO_SMASHING_DEFENSE ? race.stats.smashingDefense : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.smashingDefense;
}
Health Creature::getSlashingDefense () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.slashingDefense !=
           Stats::NO_SLASHING_DEFENSE ? race.stats.slashingDefense : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.slashingDefense;
}
Health Creature::getStabbingDefense () const {
    const Race& race = Game_Data::getRace(this->race);

    return race.stats.stabbingDefense !=
           Stats::NO_STABBING_DEFENSE ? race.stats.stabbingDefense : Game_Data::getRaceCategory(
        Game::getWorldName(), race.category).stats.stabbingDefense;
}

bool Creature::isAlive () const {
    return health > 0;
}
PixelBox Creature::getSight () const {
    Pixels sightRange = getSightRange() * Game_Constants::TILE_SIZE;
    PixelBox box = getBox();

    return PixelBox(box.center_x() - sightRange, box.center_y() - sightRange, sightRange * 2.0, sightRange * 2.0);
}

void Creature::handleCalendarMinute () {
    hunger();
    thirst();
}
void Creature::handleCalendarHour (const Index index) {
    if (Need::getThreshold(food, getMaximumFood()) == Need::Threshold::terrible) {
        takeTypelessDamage(index, max((Health) (getMaximumHealth() * Game_Constants::FOOD_HEALTH_LOSS), (Health) 1));
    }

    if (Need::getThreshold(water, getMaximumWater()) == Need::Threshold::terrible) {
        takeTypelessDamage(index, max((Health) (getMaximumHealth() * Game_Constants::WATER_HEALTH_LOSS), (Health) 1));
    }
}

void Creature::heal (Health health) {
    if (health > 0) {
        this->health += health;

        if (this->health > getMaximumHealth()) {
            this->health = getMaximumHealth();
        }
    }
}
void Creature::eat (Health food) {
    if (food > 0) {
        this->food += food;

        if (this->food > getMaximumFood()) {
            this->food = getMaximumFood();
        }
    }
}
void Creature::drink (Health water) {
    if (water > 0) {
        this->water += water;

        if (this->water > getMaximumWater()) {
            this->water = getMaximumWater();
        }
    }
}

void Creature::meleeAttack (const Index index, const Index creatureIndex) {
    Damage counterattack =
        Game::getCreature(creatureIndex).takeMeleeDamage(creatureIndex,
                                                         Damage(getMeleeDamageChance(), getMeleeAttackDamageType(),
                                                                Game::getRng().random_range(getMeleeAttackMinimumDamage(),
                                                                                            getMeleeAttackMaximumDamage())));

    if (counterattack.getAmount() > 0) {
        takeMeleeDamage(index, counterattack);
    }
}
Damage Creature::takeMeleeDamage (const Index index, const Damage& damage) {
    if (damage.damages(Game::getCreature(index))) {
        Health damageTaken = damage.getModifiedAmount(Game::getCreature(index));

        if (damageTaken >= health) {
            health = 0;
            die(index);

            return Damage(0, "", 0);
        } else {
            health -= damageTaken;

            return Damage(getMeleeDamageChance(), getMeleeAttackDamageType(),
                          Game::getRng().random_range(getMeleeAttackMinimumDamage(), getMeleeAttackMaximumDamage()));
        }
    } else {
        return Damage(getMeleeDamageChance(), getMeleeAttackDamageType(),
                      Game::getRng().random_range(getMeleeAttackMinimumDamage(), getMeleeAttackMaximumDamage()));
    }
}
void Creature::takeTypelessDamage (const Index index, const Health damage) {
    if (isAlive()) {
        if (damage >= health) {
            health = 0;
            die(index);
        } else {
            health -= damage;
        }
    }
}
void Creature::die (const Index index) {
    goal.setNone();
    attack.stop();

    Game::handleCreatureDeath(index);

    if (!isUndead()) {
        const World& world = Game_Data::getWorld(Game::getWorldName());

        if (world.deadBecomeRace.length() > 0) {
            race = world.deadBecomeRace;
            food = getMaximumFood();
            water = getMaximumWater();
            health = getMaximumHealth();
            setSprite(Game_Data::getRace(race).sprite);
        }

        if (world.deadBecomeFaction.length() > 0) {
            faction = world.deadBecomeFaction;
        }
    }

    if (!isAlive()) {
        setSprite("dead");
    }
}

void Creature::applyMoveForce (double angle) {
    PhysicsObject::applyMoveForce(getMoveForce(), angle);
}
void Creature::brake () {
    PhysicsObject::brake(getMoveForce(), getMass());
}
void Creature::accelerate () {
    PhysicsObject::accelerate(getMass(), getMaximumSpeed());
}
void Creature::movement () {
    PhysicsObject::movement(getCollisionSteps(), getCollisionReduction());
}
