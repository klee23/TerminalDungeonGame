#include "Inventory.h"

#include <stdexcept>
#include <vector>

const int Inventory::validateMaxCapacity(int cap){
    if(cap <= 0){
        throw std::invalid_argument("Cannot have inventory of less than 1.");
    }
    return cap;
}

Inventory::Inventory(int cap) : maxCapacity_(cap){ 
    inventory_;
}

bool Inventory::addItem(std::unique_ptr<Item>&& item){
    if(inventory_.size() < maxCapacity_){
        inventory_.push_back(std::move(item));
        return true;
    }

    return false;
}

std::unique_ptr<Item> Inventory::getItem(){
    if(inventory_.empty()){
        throw std::range_error("No items in inventory!");
    }

    auto result = std::move(inventory_.front());
    inventory_.erase(inventory_.begin());
    return result;
}