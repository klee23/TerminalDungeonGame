#pragma once

#include "Character.h"

class Warrior : public Character
{
public:
    Warrior(
        std::string name,
        int hp,
        int attack,
        int armor);
    
    CharacterType getType() const override;

protected:
    int calculateDamageTaken(int damage) const override;

private:
    int armor_;

    static int validateArmor(int armor);
};