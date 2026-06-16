#include "ClosestToDyingTarStrat.h"
#include "Character.h"

#include <algorithm>
#include <stdexcept>
#include <vector>


Character* ClosestToDyingTarStrat::getTarget(const Character& attacker,const std::vector<std::unique_ptr<Character>>& targets){
    if(targets.empty()){
        throw std::invalid_argument("Cannot have no targets!");
    }
    if(!attacker.isAlive()){
        throw std::runtime_error("Attacker is dead, cannot attack");
    }

    std::vector<Character*> possibleTargets;
    for(auto& target : targets){
        if(target->isAlive() && (target->getHealth()>0) ){
            possibleTargets.push_back(target.get());
        }
    }

    auto it = std::min_element(possibleTargets.begin(), possibleTargets.end(), 
      [](const auto& a, const auto& b){
        return a->getHealth() > b->getHealth();
    });

    return *it;
}