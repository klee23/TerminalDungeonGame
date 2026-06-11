#include "Character.h"
#include "ITargetStrategy.h"
#include "HealthiestTargetStratgey.h"
#include "Inventory.h"

#include <assert.h>
#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>


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

Character::Character(std::string name, int hp, int attack, int inven_size)
    : inventory_size_(inven_size),
     name_(validateName(name)),
     health_(validateHealth(hp)),
     attack_(validateAttack(attack) ) 
{   
    // todo put into constructor
    inventory_ = std::make_unique<Inventory>(10);
}

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

bool Character::addToInventory(std::unique_ptr<Item>&& item){
    return inventory_->addItem(std::move(item));
}
    
std::unique_ptr<Item> Character::takeFirstFromInventory(){
    // try???
    return std::move(inventory_->getItem());
}


int Character::calculateDamageTaken(int damage) const {
    return damage;
}

void Character::setTargetStrategy(std::unique_ptr<ITargetStrategy> tss){
    tss_ = std::move(tss);
}

const std::unique_ptr<ITargetStrategy>& Character::getTargetStrategy() const {
    return tss_;
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