#include "Orc.h"
#include "CharacterType.h"

Orc::Orc(std::string name, int hp, int attack)
    : Character(std::move(name), hp, attack)
{
}

int Orc::attack() const noexcept
{
    return static_cast<int>(Character::attack() * 1.5);
}

CharacterType Orc::getType() const {
    return CharacterType::Orc;
}