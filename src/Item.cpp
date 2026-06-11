#include "Item.h"
#include "ItemType.h"
#include <stdexcept>

const int Item::validateValue(int val){
    if(val < 0){
        throw std::invalid_argument("Item value cannot be less than zero");
    }
    return val;
}

Item::Item(int value, enum::ItemType type) : value_(value), type_(type) {}


const int Item::getValue() noexcept{
    return value_;
};

const ItemType Item::getType() noexcept{
    return type_;
}