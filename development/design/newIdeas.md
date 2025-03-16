# New ideas

## 2023 thoughts

You can setup a color palette for a faction
You can either set colors that are then used to render each part of each unit, or you can create whole pngs that use those colors
Being able to somehow paint your faction or any faction would be fun though

## Newer thoughts

* Item variants
All items, be they consumables, equipment, whatever, can have their stats modified
So any given item has its base stats
But some or all of these stats can be modified, creating a variant item type
These variants are still defined by data files, and are not procedurally generated
A variant should have a unique name and graphic (but of course, for right now there aren't really many graphics)

### Basics

* Body parts are linked to each other, and grouped together into armor slots
* Example:
Torso armor slot exists and is composed of torso and two arm body parts
A sweatshirt is a piece of armor that fits a torso armor slot, because it covers the body parts associated with that armor slot
The armor item has material, defense, and health per body part
This all means that equipment can only be worn if it fits the armor slot
Attacks hit a body part, or multiple body parts following the links if the attack damage splashes
Weapon slots should work similarly, in that they are wielded by a specific body part

* The game world has dimensions
* A creature is an object in the world
* It has a position, box, velocity, acceleration, force, sprite
* Creatures are held within the world
* Creatures have a body, made of connected body parts
* Look at the armor profile stuff below
* Body parts probably have their own health
* Armor and weapons also have their own health
* Melee attacks are implemented
* Need to consider damage, stats, materials, equipment health
* Probably a strength stat that affects the damage of melee attacks
* Also a strength requirement for equipment
* Also equipment has a size that affects who can equip it
* Can melee attacks miss?
* Are there critical hits or failures? Maybe these are handled or affected by the parts system?
* Anyway, get everything needed for melee combat implemented
* Melee attacks are doable unarmed or with a weapon equipped
* Different thresholds of part health might have specific effects, like various wound states for a body part
* Also there are consumable items that can be picked up and used
* Healing items exist
* There is basic AI for targeting a creature
* AI for item collection
* AI for item usage
* AI for attacking enemy
* AI for running for life
* Melee attacks should involve counterattacks, cooldown, attack time, vulnerability to attacks aside from target while attacking
* A counterattack should still cause a cooldown
* Only once melee combat is solid should I add ranged attacks

## New thoughts

* A creature has armor slots
* Armor items can be equipped in their respective slots
* Armor has a material
* Armor has a defense value
* Armor has health

* Need some kind of armor layering feature, to allow for multiple layers of armor to be worn at once
* Could be represented by just having multiple armor slots per body part

* Equipped items have a mass, and a creature has limits to how much mass they can equip
* There should probably also be some kind of skill requirement
* Skills should have relatively few levels possible, and at first they don't need to be able to increase or decrease
* There can be skills for things like behavior as well
* There can also be skills for teamwork
* Eventually I should add communication, which could be affected by equipment and skills, and could affect teamwork

* Creatures can fight unarmed

* Creatures should be able to have body parts replaced with augmetics

* There are melee weapons and ranged weapons
* Weapons have a material
* Weapons have an attack value
* Weapons have health
* Attacking with a weapon has a cast time and a cooldown
* Attacking with a melee weapon does damage as it collides with creatures
* Attacking with a ranged weapon fires a projectile

* While attacking, a creature should probably be more vulnerable to attacks, with the exception of their melee target (if applicable)

* A projectile has its own material and attack value
* A projectile might create an explosion

* An explosion has its own material and attack value

* When an attack lands, its damage is determined using its attack and material versus the target's defense and material
* This damage is applied to the target's health
* Before damaging the target however, both the weapon and armor might take damage themselves, affected by the same stats
* Weapon and armor damage are caused (somewhat randomly) by large percentages of over or under damage

* Alternative armour setup:
* All of the body parts and the wielded weapon(s) are connected into a contiguous layout, called the armour profile
* Each armour profile slot has layers of defense + material
* An attack has an area of effect
* An attack hits a specific armour profile slot, which is selected at random on hit
* An attack's hit slot is used with it's area of effect to determine all hit slots
* The attack's damage is applied (+ its material) evenly divided between the hit slots (with excess from rounding applied to the hit slot)
* Armour has a durability
* Armour has a durability percentage
* When a slot takes damage, the durability percentage of it is applied to the armour slot item's durability, and the rest is applied to the creature's health

* Every material has a relationship to every material, which determines a landed attack's material multiplier

* Since equipment items can be damaged, they need to be able to be repaired
* What happens if an item loses all health? Does it get destroyed or just become unequippable?

* Every creature needs its own line of sight

* Eventually I'll want vehicles, including ones with multiple crew

* Could add plot armor, which could be partial or full

* There should be a skill for melee attack and one for ranged attack
* There should also be a skill for each weapon
* Skills should only have a small number of possible values
* Each point in a skill should give a much greater buff
* Some kind of defensive skills are needed

* Attacks have damage and type, and are used against the target's armor amount and type to determine an attack result
* There should be fuzziness in attack calculations, e.g., a melee attack might be deflected by armor, negating or at least mostly preventing damage

* The destruction of armour or weapons can cause shrapnel, depending on how it was destroyed, to fly out as projectiles

I had some good ideas I think when falling asleep recently...
It had to do with melee attacking
Oh!
Melee and ranged attacks both need a like windup time, and melee should be faster generally I think
Omg! And!
Ranged shots are physically simulated
Ranged weapons have an accuracy, which is an angle in degrees.
All other things being equal, when a shot is fired, the shot spawns moving at a random angle within the weapon's accuracy range, centered on the angle to the target

I assume I have skills of some kind designed right?
Weapons should be divided into classes, and there is a corresponding skill for each class.
Each weapon should also have its own skill.

There should be a way to design your own world that is easy for players
