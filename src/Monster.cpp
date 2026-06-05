#include "Monster.h"
#include "Character.h"
#include "CharacterType.h"
#include <algorithm>
#include <stdexcept>

int Monster::validateArmor(int armor){
    if(armor < 0){
        throw std::invalid_argument("Armor cannot be less than zero!");
    }
    return armor;
}

int Monster::validateStrength(int strn){
    if(strn < 0){
        throw std::invalid_argument("Strength cannot be less than zero!");
    }
    return strn;
}

Monster::Monster(std::string name, int hp, int attack, int armor, int strength) : 
    Character(name, hp, attack) , 
    armor_(validateArmor(armor)), 
    strength_(validateStrength(strength)) {
    // ?????
}

int Monster::calculateDamageTaken(int damage) const {
    damage = std::max(damage - armor_, 0);; // can't do negative damage.
    return damage;
}

int Monster::attack() const noexcept{
    return static_cast<int>(Character::attack() * (strength_*0.5));
}

CharacterType Monster::getType() const{
    return CharacterType::Monster;
}