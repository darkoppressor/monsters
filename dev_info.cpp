/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "game.h"

#include <engine.h>
#include <game_manager.h>
#include <font.h>
#include <object_manager.h>
#include <options.h>
#include <network_engine.h>
#include <render.h>
#include <engine_strings.h>

using namespace std;

void Engine::render_dev_info () {
    string msg = "";

    if (Game_Manager::in_progress) {
        msg += "Camera Position: " + Strings::num_to_string(Game_Manager::camera.x) + ", " + Strings::num_to_string(
            Game_Manager::camera.y) + "\n";
        msg += "Camera Size: " + Strings::num_to_string(Game_Manager::camera.w / Game_Manager::camera_zoom) + ", " +
               Strings::num_to_string(Game_Manager::camera.h / Game_Manager::camera_zoom) + "\n";
        msg += "Camera Zoom: " + Strings::num_to_string(Game_Manager::camera_zoom) + "\n";

        for (Index i = 0; i < Game::getCreatureCount(); i++) {
            Creature& creature = Game::getCreature(i);
            msg += "\nCreature " + Strings::num_to_string(i) + ":\n";
            PixelBox box = creature.getBox();
            msg += "  Position: " + Strings::num_to_string(box.x) + ", " + Strings::num_to_string(box.y) + "\n";
            msg += "  Health: " + Strings::num_to_string(creature.getHealth()) + "/" + Strings::num_to_string(
                creature.getMaximumHealth()) + "\n";
            msg += "  Food: " + Strings::num_to_string(creature.getFood()) + "/" + Strings::num_to_string(
                creature.getMaximumFood()) + "\n";
            msg += "  Water: " + Strings::num_to_string(creature.getWater()) + "/" + Strings::num_to_string(
                creature.getMaximumWater()) + "\n";
            msg += "  Race: " + creature.getRace() + "\n";
            msg += "  Faction: " + creature.getFaction() + "\n";
            msg += "  Goal:\n";
            msg += "    Type: " + creature.getGoal().getTypeString() + "\n";
            msg += "    Target index: " + Strings::num_to_string(creature.getGoal().getTargetIndex()) + "\n";
            msg += "  Attack:\n";
            msg += "    Cooling down: " +
                   Strings::bool_to_string(creature.getAttack().getCooldownCounter().isCounting()) + "\n";
            msg += "    Cooldown count: " +
                   Strings::num_to_string(creature.getAttack().getCooldownCounter().getCount()) + "\n";
            msg += "    Preparing: " +
                   Strings::bool_to_string(creature.getAttack().getPreparationCounter().isCounting()) + "\n";
            msg += "    Preparation count: " + Strings::num_to_string(
                creature.getAttack().getPreparationCounter().getCount()) + "\n";
            msg += "  Equipment:\n";
            msg += "    Melee weapon: " +
                   (creature.getEquipment().hasMeleeWeapon() ? creature.getEquipment().getMeleeWeapon().displayName :
                    "not equipped") + "\n";
            msg += "  Consumables:\n";

            for (const auto& consumable : creature.getConsumables().getKeys()) {
                msg += "    " + consumable + ": " +
                       Strings::num_to_string(creature.getConsumables().getItemCount(consumable)) + "\n";
            }
        }
    }

    if (msg.length() > 0) {
        Bitmap_Font* font = Object_Manager::get_font("small");
        double y = 2.0;

        if (Options::fps) {
            y += font->spacing_y;

            if (Network_Engine::status != "off") {
                y += font->spacing_y * 2.0;
            }
        }

        Render::render_rectangle(2.0, y, Strings::longest_line(msg) * font->spacing_x, Strings::newline_count(
                                     msg) * font->spacing_y, 0.75, "ui_black");
        font->show(2.0, y, msg, "red");
    }
}
