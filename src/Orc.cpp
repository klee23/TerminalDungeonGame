#include "Orc.h"
#include "CharacterType.h"
#include "HealthiestTargetStratgey.h"

Orc::Orc(std::string name, int hp, int attack)
    : Character(std::move(name), hp, attack)
{
    Character::setTargetStrategy( std::move(std::make_unique<HealthiestTargetStratgey>()));
}

int Orc::attack() const noexcept
{
    return static_cast<int>(Character::attack() * 1.5);
}

CharacterType Orc::getType() const {
    return CharacterType::Orc;
}


Character* Orc::selectTarget(std::vector<std::unique_ptr<Character>>& targets) const {
    return Character::getTargetStrategy()->getTarget(*this, targets);
}