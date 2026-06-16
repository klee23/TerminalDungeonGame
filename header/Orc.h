#pragma once

#include "Character.h"

class Orc : public Character
{
public:
    Orc(std::string name, int hp, int attack);

    int attack() const noexcept override;
    CharacterType getType() const override;
    Character* selectTarget(std::vector<std::unique_ptr<Character>>& targets) const override;
    int calculateDamageTaken(int) const override;
};