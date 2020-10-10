/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#ifndef game_h
#define game_h

#include "base_types.h"
#include "tile.h"
#include "creature.h"

#include <rng.h>

class Game {
    private:
        static RNG rng;
        static uint32 frame;
        static String worldName;
        static List<List<Tile>> tiles;
        static List<Creature> creatures;
        static Quad quadtree;
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
        static const Quad& getQuadtree();
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
