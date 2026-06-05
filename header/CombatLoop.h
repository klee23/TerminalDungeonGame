#pragma once

#include <memory>
#include <vector>

#include "Character.h"

class CombatLoop{

public:
    void doCombat(Character& , Character&);
    void doCombat(std::vector<std::unique_ptr<Character>>& , std::vector<std::unique_ptr<Character>>&);
private:
};