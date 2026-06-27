#pragma once

#include "Character.h"
#include "Weapon.h"

class Orc : public Character
{
public:
    Orc(std::string name, int hp, int attack);

    int attack() const noexcept override;
    CharacterType getType() const override;
    Character* selectTarget(std::vector<std::unique_ptr<Character>>& targets) const override;
    int calculateDamageTaken(int) const override;

    void equipWeapon();
    void removeWeapon();

private:
    Weapon* equiped_weapon_;

};