#pragma once

#include <vector>

#include "Character.h"

class CombatLoop{
private:
    std::vector<Character> chars_;
public:

    CombatLoop() = default;
    // todo. destructor? copy? move?

    void doCombat(Character& , Character&);
};