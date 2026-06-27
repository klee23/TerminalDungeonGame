#include "Warrior.h"
#include "Armor.h"
#include "Character.h"
#include "CharacterType.h"
#include "HealthiestTargetStratgey.h"
#include "Weapon.h"

#include <cstddef>
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
    equiped_armor_ = nullptr;
}

int Warrior::attack() const noexcept {
    Weapon* weap = inventory_.getStrongestWeapon();
    int totalDamage = Character::attack();
    if(weap){
        totalDamage += inventory_.getStrongestWeapon()->getAttackValue();
    } 
    
    return totalDamage;
}

int Warrior::calculateDamageTaken(int damage) const
{
    if(equiped_armor_){
        damage -= armor_;
    }

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

void Warrior::equipArmor(){
    equiped_armor_ = inventory_.getStrongestArmor();
}

void Warrior::removeArmor(){
    equiped_armor_ = nullptr;
}

CharacterType Warrior::getType() const {
    return CharacterType::Warrior;
}

Character* Warrior::selectTarget(std::vector<std::unique_ptr<Character>>& targets) const {
    return Character::getTargetStrategy()->getTarget(*this, targets);
}