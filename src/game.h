/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef game_h
#define game_h

#include "base_types.h"
#include "tile.h"
#include "creature.h"
#include "item.h"
#include "calendar.h"

#include <rng.h>

class Game {
    private:
        static RNG rng;
        static uint32 frame;
        static String worldName;
        static Calendar calendar;
        static List<List<Tile>> tiles;
        static List<Creature> creatures;
        static List<Creature> newCreatures;
        static uint32 deadCreatures;
        static List<Item> items;
        static List<Item> newItems;
        static Quad creatureQuadtree;
        static Quad itemQuadtree;

    public:
        static RNG& getRng();
        static uint32 getFrame();
        static const String& getWorldName();
        static Tiles getWorldTileWidth();
        static Tiles getWorldTileHeight();
        static Pixels getWorldWidth();
        static Pixels getWorldHeight();
        static Index getCreatureCount();
        static Creature& getCreature(const Index index);
        static void handleCreatureDeath(const Index index);
        static void handleCreatureDeletion(const Index index);
        static Item& getItem(const Index index);
        static void handleItemCollection(const Index index);
        static void handleItemDeletion(const Index index);
        static void addCreature(const TileCoords& position, const String& race, const String& faction);
        static void addEquipment(const TileCoords& position, const String& item);
        static void addConsumable(const TileCoords& position, const String& item);
        static const Quad& getCreatureQuadtree();
        static const Quad& getItemQuadtree();
        static void clear_world();
        static void generate_world();
        static void tick();
        static void ai();
        static void movement();
        static void events();
        static void animate();
        static void render();
        static void render_to_textures();
        static void update_background();
        static void render_background();
        static bool moveInputState(std::string direction);
};

#endif
