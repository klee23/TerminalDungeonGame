#pragma once

#include "Character.h"

#include <string>

class Wizard : public Character
{
public:
    Wizard(std::string name, int hp, int attack, int mana);

    int GetMana() const noexcept;

    void CastSpell();
    int getAttackDamage() const noexcept override;

protected:
    int calculateDamageTaken(int damage) const override;

private:
    int mana_;
    int charged_mana_;
    static int validateMana(int);

};