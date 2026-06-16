#include "Consumable.h"
#include "Item.h"
#include "ItemType.h"

Consumable::Consumable(int con, int val) : consumeValue_(Item::validateLTETZeroValue(con)),
Item(val, ItemType::Potion){

}

int Consumable::getCosumerValue() const {
    return consumeValue_;
}