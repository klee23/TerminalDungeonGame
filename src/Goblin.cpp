#include "Goblin.h"
#include "Character.h"
#include "CharacterType.h"
#include "HealthiestTargetStratgey.h"
#include <stdexcept>

int Goblin::ValidateNonNegative(int value, std::string_view fieldName)
{
    if (value < 0)
    {
        throw std::invalid_argument(std::string(fieldName) + " cannot be less than zero!");
    }

    return value;
}


Goblin::Goblin(std::string name, int hp, int attack, int armor, int strength, int speed) :
Character(name, hp, attack),
armor_(ValidateNonNegative(armor, "Armor")),
strength_(ValidateNonNegative(strength, "Strength")),
speed_(ValidateNonNegative(speed, "Speed")) {
    Character::setTargetStrategy( std::move(std::make_unique<HealthiestTargetStratgey>()));
}

int Goblin::calculateDamageTaken(int damage) const{
    return std::max(damage - ( std::min(armor_, 5) ), 0);
}

int Goblin::attack() const noexcept{
    return Character::attack() + strength_;
}

CharacterType Goblin::getType() const{
    return CharacterType::Goblin;
}

Character* Goblin::selectTarget(std::vector<std::unique_ptr<Character>>& targets) const {
    return Character::getTargetStrategy()->getTarget(*this, targets);
}