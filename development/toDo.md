# To do

Creatures have a maximum mass for equipment they can use
Starting equipment chances for races

Add ranged weapons, slot, and the ability to do ranged attacks
Add ammo types, with consumable items for each
Ammo is consumed directly by its corresponding ranged weapon when the weapon fires

Need some kind of AI goal prioritizing eventually
Currently, AiChoice has a priority, but it is 0 for everything
Instead, each AiGoal type should have a corresponding priority
Also, some AiGoal types essentially have subtypes (e.g., getItem can be getting different item types)
In this case, the item type and how badly it is needed should factor into the priority
Additionally, both CreatureTarget and ItemTarget currently sort by just distance, but this should be expanded
E.g., ItemTarget should also take into account need for item, alongside distance

Need some kind of AI goal interruption eventually?

Add AI scores for relative strength of nearby friendlies vs hostiles when deciding whether to attack a creature
Add retreating as a goal
Retreating can happen if the above score is too nasty, or if the creature is weak
Retreating runs towards the nearest friendly creature
A Creature's weakness is based on its health level and needs
Figure out prioritizing of all current goals

Eventually with Tiles I need a concept of shelter
A Creature might prefer shelter to nearest friendly when deciding where to retreat to
Creatures need sleep, which contributes to weakness
Sleep need is refilled by sleeping, which requires shelter and no nearby enemies
With Tiles I also want a concept of home
Retreating to home could be the ultimate panic action
