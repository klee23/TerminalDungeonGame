#pragma once

#include "ITargetStrategy.h"
#include "Character.h"

class HealthiestTargetStratgey : public ITargetStrategy{
public:

    ~HealthiestTargetStratgey() = default;
    Character* getTarget(const Character&,const std::vector<std::unique_ptr<Character>>& t);

private:

};