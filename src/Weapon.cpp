#include "Weapon.h"
#include "Item.h"
#include <stdexcept>

Weapon::Weapon(int attackValue ,int moneyValue) : 
attackValue_(Item::validateLTETZeroValue(attackValue)), Item(moneyValue, ItemType::Weapon)
{

}

int Weapon::getAttackValue() const {
    return attackValue_;
}