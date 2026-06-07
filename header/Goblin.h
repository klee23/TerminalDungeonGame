#pragma once
#include "Character.h"
#include "CharacterType.h"
#include <string_view>

class Goblin : public Character {
public:
    Goblin(std::string, int, int, int, int, int);

    int calculateDamageTaken(int damage) const override;
    int attack() const noexcept override;

    CharacterType getType() const override;
    Character* selectTarget(std::vector<std::unique_ptr<Character>>& targets) const override;

private:
    int armor_;
    int strength_;
    int speed_;

    static int ValidateNonNegative(int, std::string_view);
};