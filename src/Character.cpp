#include "Character.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

Character::Character(std::string name, int hp, int attack)
    : name_(name), health_(hp), attack_(attack) {}

void Character::takeDamage(int damage) {
    if(damage < 0){
        throw std::invalid_argument("Cannot deal negative damage!");
    }
    health_ = std::max(health_ - damage, 0);
}

bool Character::isAlive() const { return (health_ >= 1); }

int Character::getHealth() const noexcept { return health_; }

int Character::attack() const noexcept { return attack_; }

std::string Character::getName() const noexcept { return name_; }

std::string Character::getStatus() const {
    std::stringstream oss;
    std::string aliveness = ( isAlive() ? "alive " : "not alive ");
    oss << getName() << " is " << aliveness << "with "
            << std::to_string(getHealth()) << " health remaining."
            << std::endl;
    return oss.str();
}