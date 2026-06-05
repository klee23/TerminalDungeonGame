#pragma once
#include <string>
#include "CharacterType.h"

class Character
{
public:
    Character(std::string name, int hp, int attack);
    virtual ~Character() = default;

    void defend(int damage);
    virtual int attack() const noexcept;

    bool isAlive() const ;
    int getHealth() const noexcept;
    const std::string& getName() const noexcept;
    std::string getStatus() const;

    virtual CharacterType getType() const = 0;

protected:
    virtual int calculateDamageTaken(int) const;

private:
    std::string name_;
    int attack_; 
    int health_; 

    static int validateHealth(int hp);
    static int validateAttack(int attack);
    static std::string validateName(std::string name);
};