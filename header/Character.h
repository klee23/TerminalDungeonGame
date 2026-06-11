#pragma once
#include <string>
#include <vector>
#include <memory>
#include "CharacterType.h"
#include "ITargetStrategy.h"
#include "Inventory.h"
#include "Item.h"

class Character
{
public:
    Character(std::string name, int hp, int attack, int inven_size=10);
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

    bool addToInventory(std::unique_ptr<Item>&&);
    std::unique_ptr<Item> takeFirstFromInventory();

protected:
    virtual int calculateDamageTaken(int) const;
    const std::unique_ptr<ITargetStrategy>& getTargetStrategy() const; // return just ITargetStrategy

private:
    std::unique_ptr<ITargetStrategy> tss_;
    std::string name_;
    int attack_; 
    int health_; 
    int inventory_size_;
    std::unique_ptr<Inventory> inventory_;

    static int validateHealth(int hp);
    static int validateAttack(int attack);
    static std::string validateName(std::string name);
};