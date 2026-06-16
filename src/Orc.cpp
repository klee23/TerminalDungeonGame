#include "Orc.h"
#include "Armor.h"
#include "Character.h"
#include "CharacterType.h"
#include "HealthiestTargetStratgey.h"
#include <algorithm>

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

int Orc::calculateDamageTaken(int damage) const {
    Armor* armor = inventory_.getStrongestArmor();
    int damageTaken = Character::calculateDamageTaken(damage);
    if(armor){
        damageTaken =  std::min( damageTaken - static_cast<int>((armor->getDefenseValue()*0.5)), 0);
    }

    return damageTaken;
}

Character* Orc::selectTarget(std::vector<std::unique_ptr<Character>>& targets) const {
    return Character::getTargetStrategy()->getTarget(*this, targets);
}