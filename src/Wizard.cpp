#include "Wizard.h"
#include "CharacterType.h"
#include "HealthiestTargetStratgey.h"

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
    Character::setTargetStrategy( std::move(std::make_unique<HealthiestTargetStratgey>()));
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

int Wizard::consumeManaChargedAttack(){
    int damage = attack();
    mana_ = 0; // consume all mana!
    return damage;
}

int Wizard::calculateDamageTaken(int damage) const
{
    return damage;
}

int Wizard::attack() const noexcept {
    return Character::attack()*(1+charged_mana_);
}

CharacterType Wizard::getType() const{
    return CharacterType::Wizard;
}


Character* Wizard::selectTarget(std::vector<std::unique_ptr<Character>>& targets) const {
    return Character::getTargetStrategy()->getTarget(*this, targets);
}