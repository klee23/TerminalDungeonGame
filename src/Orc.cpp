#include "Orc.h"
#include "Armor.h"
#include "Character.h"
#include "CharacterType.h"
#include "HealthiestTargetStratgey.h"
#include <algorithm>

Orc::Orc(std::string name, int hp, int attack)
    : equiped_weapon_(nullptr), Character(std::move(name), hp, attack)
{
    Character::setTargetStrategy( std::move(std::make_unique<HealthiestTargetStratgey>()));
}

int Orc::attack() const noexcept
{
    int attack_dmg = static_cast<int>(Character::attack() * 1.5);
    if(equiped_weapon_){
        attack_dmg += equiped_weapon_->getAttackValue();
    }
    return attack_dmg;
}

CharacterType Orc::getType() const {
    return CharacterType::Orc;
}

void Orc::equipWeapon(){
    equiped_weapon_ = inventory_.getStrongestWeapon();
}

void Orc::removeWeapon(){
    equiped_weapon_ = nullptr;
}

int Orc::calculateDamageTaken(int damage) const {
    Armor* armor = inventory_.getStrongestArmor();
    int damageTaken = Character::calculateDamageTaken(damage);
    if(armor){
        damageTaken =  std::max( damageTaken - static_cast<int>((armor->getDefenseValue()*0.5)), 0);
    }

    return damageTaken;
}

Character* Orc::selectTarget(std::vector<std::unique_ptr<Character>>& targets) const {
    return Character::getTargetStrategy()->getTarget(*this, targets);
}