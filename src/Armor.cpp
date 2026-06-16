#include "Armor.h"
#include "Item.h"
#include "ItemType.h"

Armor::Armor(int defenseValue, int moneyValue) : defenseValue_(Item::validateLTETZeroValue(defenseValue) ),
Item(moneyValue, ItemType::Armor)
{
    
}

int Armor::getDefenseValue() const {
    return defenseValue_;
}