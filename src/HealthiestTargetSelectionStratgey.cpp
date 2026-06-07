#include "Character.h"
#include "HealthiestTargetStratgey.h"

#include <algorithm>
#include <stdexcept>
#include <vector>


Character* HealthiestTargetStratgey::getTarget(const Character& attacker, 
                                   const std::vector<std::unique_ptr<Character>>& targets){
    if(targets.empty()){
        throw std::invalid_argument("Cannot have no targets!");
    }
    if(!attacker.isAlive()){
        throw std::runtime_error("Attacker is dead, cannot attack");
    }

    std::vector<Character*> living;
    for(const auto& target: targets){
        if(target->isAlive()){
            living.push_back(target.get());
        }
    }

    if(living.empty()){
        return nullptr;
    }

    auto it = std::max_element(living.begin(), living.end(), 
        [](const auto& a, const auto& b){
            return a->getHealth() < b->getHealth();
        });

    return *it;
}