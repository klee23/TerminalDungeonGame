#pragma once
#include "Character.h"

class Monster : public Character {
public:
    Monster(std::string, int, int, int, int);

    int calculateDamageTaken(int damage) const override;
    int attack() const noexcept override;
    CharacterType getType() const override;
    Character* selectTarget(std::vector<std::unique_ptr<Character>>& targets) const override;

private:
    int armor_;
    int strength_;

    static int validateArmor(int);
    static int validateStrength(int);
};