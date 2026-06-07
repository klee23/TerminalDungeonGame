#pragma once
#include <string>
#include <vector>
#include <memory>
#include "CharacterType.h"
#include "ITargetStrategy.h"

class Character
{
public:
    Character(std::string name, int hp, int attack);
    virtual ~Character() = default; // todo fix this.

    void defend(int damage);
    virtual int attack() const noexcept;
    virtual CharacterType getType() const = 0;
    virtual Character* selectTarget(std::vector<std::unique_ptr<Character>>& targets) const = 0;
    void setTargetStrategy(std::unique_ptr<ITargetStrategy> tss);

    bool isAlive() const ;
    int getHealth() const noexcept;
    const std::string& getName() const noexcept;
    std::string getStatus() const;

protected:
    virtual int calculateDamageTaken(int) const;
    const std::unique_ptr<ITargetStrategy>& getTargetStrategy() const;

private:
    std::unique_ptr<ITargetStrategy> tss_;
    std::string name_;
    int attack_; 
    int health_; 

    static int validateHealth(int hp);
    static int validateAttack(int attack);
    static std::string validateName(std::string name);
};