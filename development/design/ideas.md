# Ideas

Simulation toy / game
Singleplayer
2D tile graphics
Top down view

Highly configurable simulation of a city being inhabited by various creatures with various interrelationships

Put simply: you fill a little world with people and monsters and then watch them interact, with a heavy emphasis on murdering each other

Both fantasy and science fiction type things can be included
Players can build their simulation exactly how they want
Watch zombies fight human soldiers, civilians, vampires, or giant mechs
Also if I could get awesome Warhammer 40K races (ish) to battle each other that would amazing

There should definitely be a cover system for combat that makes use of tiles

TODO:
STILL NEED TO IMPLEMENT AI GOAL WEIGHTS

For creatures:
Add ranged attack stats

Other potential damage types:
Explosive
Burning
Ripping

How might I implement things like thrown grenades and molotov cocktails?

For example, humans might use some flocking behavior with other friendly humans, so that they coalesce into cooperating groups
Or humans might attack zombies on sight or retreat from them

So faction relationships affect individual creature interactions
Factions themselves can optionally include certain high level AI inputs
For example, a faction of human soldiers might have a relationship with other human factions that causes them to prioritize protecting them, but the faction itself might have a morale level that causes the soldiers to become more cautious and less willing to help those same factions (or anyone else) as it gets lower

The world is 2D and composed of a grid of tiles

Tiles have a ground material
Tiles have an optional ceiling material, which if present means the tile is indoors
Tiles have a type, such as nothing, wall, or car
Tiles have a material
Tiles can have their type and materials changed by interactions with stuff

Materials have various stats like flammability, strength, etc.

Need a toggle for making all, none, or hovered ceiling tiles transparent

Any tile with a ceiling is considered indoors

Buildings are defined by the tiles that make them up
A tile can be in 0 or 1 buildings at any time
Buildings have a type

AI behaviors include things like:
What kind of tile to look for and move to (e.g., it is daytime and a human with a job moves to the nearest building with a type that matches that job

Creatures need to be able to have a base that they defend and return to
They don't have to have a base
A base should be a simple tile and radius
A creature picks its base based on various tile factors (and maybe nearby allied bases)
A creature can abandon their base

Creatures might have a preferred temperature
Climate, time of day, weather, and tiles all combine to determine local temperature for a creature

Creatures have sleep need
Ticks down like other needs
Refilled by sleeping
Tiles have restful rating
Creatures try to sleep on a closer, higher rating tile

Tiles should be able to provide cover from ranged attacks
Can I make creatures know how to use or bypass cover?
If a creature is trying to close to attack a creature, it should consider its target's cover
