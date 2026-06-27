#pragma once

#include "Armor.h"
#include "Character.h"

class Warrior : public Character
{
public:
    Warrior(
        std::string name,
        int hp,
        int attack,
        int armor);
    
    int attack() const noexcept override;
    CharacterType getType() const override;
    Character* selectTarget(std::vector<std::unique_ptr<Character>>& targets) const override;

    void equipArmor();
    void removeArmor();

protected:
    int calculateDamageTaken(int damage) const override;

private:
    int armor_;

    Armor* equiped_armor_;

    static int validateArmor(int armor);
};