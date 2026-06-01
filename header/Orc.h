#pragma once

#include "Character.h"

class Orc : public Character
{
public:
    Orc(std::string name, int hp, int attack);

    int getAttackDamage() const noexcept override;
};