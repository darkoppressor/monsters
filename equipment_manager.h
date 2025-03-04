/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef equipment_manager_h
#define equipment_manager_h

#include "base_types.h"
#include "equipment_type.h"

class EquipmentManager {
    private:
        String meleeWeapon;
        String headArmor;
        String torsoArmor;
        String handArmor;
        String legArmor;
        String footArmor;

    public:
        EquipmentManager ();
        bool hasMeleeWeapon() const;
        const EquipmentType& getMeleeWeapon() const;
        bool hasHeadArmor() const;
        const EquipmentType& getHeadArmor() const;
        bool hasTorsoArmor() const;
        const EquipmentType& getTorsoArmor() const;
        bool hasHandArmor() const;
        const EquipmentType& getHandArmor() const;
        bool hasLegArmor() const;
        const EquipmentType& getLegArmor() const;
        bool hasFootArmor() const;
        const EquipmentType& getFootArmor() const;

        double getMass() const;

        void equip(const String& item, const TileCoords& position);
};

#endif
