#pragma once

#include "ITargetStrategy.h"
#include "Character.h"

class ClosestToDyingTarStrat : public ITargetStrategy{
    
    ~ClosestToDyingTarStrat() = default;
    Character* getTarget(const Character&,const std::vector<std::unique_ptr<Character>>& t);
};