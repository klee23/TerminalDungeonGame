#include "Warrior.h"
#include "CharacterType.h"
#include "HealthiestTargetStratgey.h"

#include <stdexcept>

Warrior::Warrior(
    std::string name,
    int hp,
    int attack,
    int armor)
    : Character(std::move(name), hp, attack)
    , armor_(validateArmor(armor))
{
    Character::setTargetStrategy( std::move(std::make_unique<HealthiestTargetStratgey>()));
}

int Warrior::calculateDamageTaken(int damage) const
{
    damage -= armor_;

    if (damage < 0)
    {
        damage = 0;
    }

    return damage;
}

int Warrior::validateArmor(int armor)
{
    if (armor < 0)
    {
        throw std::invalid_argument(
            "Armor cannot be less than zero.");
    }

    return armor;
}

CharacterType Warrior::getType() const {
    return CharacterType::Warrior;
}

Character* Warrior::selectTarget(std::vector<std::unique_ptr<Character>>& targets) const {
    return Character::getTargetStrategy()->getTarget(*this, targets);
}