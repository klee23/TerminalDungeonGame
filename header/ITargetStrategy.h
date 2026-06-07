#pragma once

#include <memory>
#include <vector>

class Character;

class ITargetStrategy{
public:

    virtual ~ITargetStrategy() = default;
    virtual Character* getTarget(const Character& attacker,const std::vector<std::unique_ptr<Character>>& t) = 0;

private:


};