#include "Item.h"
#include "ItemType.h"
#include <stdexcept>

int Item::validateLTETZeroValue(int in){
    if (in <=0) {
        throw std::invalid_argument("Item cannot have value less than or equal to zero.");
    }
    return in;
}

const int Item::validateValue(int val){
    if(val < 0){
        throw std::invalid_argument("Item value cannot be less than zero");
    }
    return val;
}

Item::Item(int value, enum::ItemType type) : value_(value), type_(type) {}


int Item::getValue() const noexcept{
    return value_;
};

ItemType Item::getType() const noexcept{
    return type_;
}