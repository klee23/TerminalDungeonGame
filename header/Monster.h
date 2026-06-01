#pragma once
#include "Character.h"

class Monster : public Character {
public:
    Monster(std::string, int, int, int, int);

    int calculateDamageTaken(int damage) const override;
    int getAttackDamage() const noexcept override;

private:
    int armor_;
    int strength_;

    static int validateArmor(int);
    static int validateStrength(int);
};