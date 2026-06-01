#pragma once
#include "Character.h"
#include <string_view>

class Goblin : public Character {
public:
    Goblin(std::string, int, int, int, int, int);

    int calculateDamageTaken(int damage) const override;
    int getAttackDamage() const noexcept override;

private:
    int armor_;
    int strength_;
    int speed_;

    static int ValidateNonNegative(int, std::string_view);
};