#include "Wizard.h"

#include <string>
#include <stdexcept>

int Wizard::validateMana(int mana){
    if(mana<0){
        throw std::invalid_argument("Mana cannot be less than zero!!");
    }
    return mana;
}

Wizard::Wizard(std::string name, int hp, int attack, int mana)
    : Character(std::move(name), hp, attack)
    , mana_(validateMana(mana))
    , charged_mana_(0)
{
}

int Wizard::GetMana() const noexcept
{
    return mana_;
}

void Wizard::CastSpell()
{
    if(mana_ > 1){
        mana_ = mana_-1;
        charged_mana_ = charged_mana_ + 1; // unlimited charge!!
    }
}

int Wizard::calculateDamageTaken(int damage) const
{
    return damage;
}

int Wizard::getAttackDamage() const noexcept {
    return Character::getAttackDamage()*(1+charged_mana_);
}