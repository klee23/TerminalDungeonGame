#pragma once
#include <string>

class Character
{
public:
    Character(std::string name, int hp, int attack);

    bool isAlive() const ;

    void takeDamage(int damage);

    int getHealth() const noexcept;

    int attack() const noexcept;

    std::string getName() const noexcept;
    
    std::string getStatus() const;

protected:
    std::string name_;
    int health_; // TODO:must be greater than zero
    int attack_; // TODO:must be greater than zero
};