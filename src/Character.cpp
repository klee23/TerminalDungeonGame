#include "Character.h"

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>


int Character::validateHealth(int hp){
    if(hp<=0){
        throw std::invalid_argument("Health cannot be zero or less!");
    }
    return hp;
}

int Character::validateAttack(int attack){
    assert(attack>=0);
    if(attack<0){
        throw std::invalid_argument("Attack cannot be less than zero!");
    }
    return attack;
}

std::string Character::validateName(std::string name){
    assert(!name.empty());
    if(name.empty()){
        throw std::invalid_argument("Name cannot be empty");
    }
    return name;
}

Character::Character(std::string name, int hp, int attack)
    : name_(validateName(name)),
     health_(validateHealth(hp)),
     attack_(validateAttack(attack)) {}

// a Template Method...
void Character::defend(int damage) {
    if(damage < 0){
        throw std::invalid_argument("Cannot deal negative damage!");
    }
    // calcualte damage done.
    int damage_done = calculateDamageTaken(damage);
    // reduce health.
    health_ = std::max(health_ - damage_done, 0);
    // check for death
    bool bAlive = isAlive();
}

int Character::calculateDamageTaken(int damage) const {
    return damage;
}

bool Character::isAlive() const { return (health_ >= 1); }

int Character::getHealth() const noexcept { return health_; }

int Character::attack() const noexcept { return attack_; }

const std::string& Character::getName() const noexcept { return name_; }

std::string Character::getStatus() const {
    std::stringstream oss;
    std::string aliveness = ( isAlive() ? "alive " : "not alive ");
    oss << getName() << " is " << aliveness << "with "
            << std::to_string(getHealth()) << " health remaining."
            << std::endl;
    return oss.str();
}