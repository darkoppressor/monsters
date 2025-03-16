/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef game_data_h
#define game_data_h

#include "base_types.h"
#include "world.h"
#include "race.h"

#include <ui/progress_bar.h>
#include <file/file_io.h>

class Game_Data {
    private:
        static UnorderedMap<String, World> worlds;
        static UnorderedMap<String, Race> races;

    public:
        // The total number of progress bar items in load_data_game()
        static const int game_data_load_item_count;

        static void load_data_game(Progress_Bar& bar);
        // Load any data of the passed tag type
        // Returns false if passed tag type's data could not be loaded
        // Returns true otherwise
        static void load_data_tag_game(std::string tag, File_IO_Load* load);
        static void unload_data_game();
        static bool loadStat(std::string& line, Stats& stats);
        static void loadWorld(File_IO_Load* load);
        static std::size_t loadRaceCategory(std::vector<std::string>& lines, std::size_t lineIndex, World& world);
        static std::size_t loadFaction(std::vector<std::string>& lines, std::size_t lineIndex, World& world);
        static std::size_t loadEquipmentType(std::vector<std::string>& lines, std::size_t lineIndex, World& world);
        static std::size_t loadConsumableType(std::vector<std::string>& lines, std::size_t lineIndex, World& world);
        static const World& getWorld(const String& name);
        static const RaceCategory& getRaceCategory(const String& worldName, const String& name);
        static const Faction& getFaction(const String& worldName, const String& name);
        static const EquipmentType& getEquipmentType(const String& worldName, const String& name);
        static const ConsumableType& getConsumableType(const String& worldName, const String& name);
        static void loadRace(File_IO_Load* load);
        static const Race& getRace(const String& name);
};

#endif
