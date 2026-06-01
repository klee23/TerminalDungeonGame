#include "Orc.h"

Orc::Orc(std::string name, int hp, int attack)
    : Character(std::move(name), hp, attack)
{
}

int Orc::getAttackDamage() const noexcept
{
    return static_cast<int>(Character::getAttackDamage() * 1.5);
}