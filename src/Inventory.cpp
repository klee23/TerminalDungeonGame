#include "Inventory.h"
#include "Armor.h"
#include "ItemType.h"
#include "Weapon.h"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

const int Inventory::validateMaxCapacity(int cap){
    if(cap <= 0){
        throw std::invalid_argument("Cannot have inventory of less than 1.");
    }
    return cap;
}

Inventory::Inventory(int cap) : maxCapacity_(validateMaxCapacity(cap)){ 
    inventory_;
}

bool Inventory::addItem(std::unique_ptr<Item>&& item){
    item->getType();

    if(inventory_.size() < maxCapacity_){
        inventory_.push_back(std::move(item));
        return true;
    }

    return false;
}

std::optional<size_t> Inventory::findFirstItemType(ItemType type) const{
    auto it = std::find_if(inventory_.begin(), inventory_.end(), 
        [type](auto& a){ return a->getType() == type; });
    
    if(it == inventory_.end()){
        return std::nullopt;
    }

    return static_cast<size_t>(std::distance(inventory_.begin(), it));
}


std::unique_ptr<Item> Inventory::extractItemById(int id){
    // TODO: throw? if id > capacity?
    auto rv = std::move(inventory_[id]);
    inventory_.erase(inventory_.begin() + id);

    return rv;
}


Weapon* Inventory::getStrongestWeapon() const{
    Weapon* strongest_weapon = nullptr;

    for(auto& item : inventory_){
        if(item->getType() != ItemType::Weapon){
            continue;
        }

        auto* curr_weap = dynamic_cast<Weapon*>(item.get());

        if(strongest_weapon == nullptr || 
        curr_weap->getAttackValue() > 
        strongest_weapon->getAttackValue()){
            strongest_weapon = curr_weap;
        }
    }

    return strongest_weapon;
}

Armor* Inventory::getStrongestArmor() const{
    Armor* strongest_armor = nullptr;

    for(auto& item : inventory_){
        if(item->getType() != ItemType::Armor){
            continue;
        }

        Armor* curr_armor =dynamic_cast<Armor*>(item.get());

        if(strongest_armor == nullptr || 
            strongest_armor->getDefenseValue() < curr_armor->getDefenseValue() ){
            strongest_armor = curr_armor;
        }
    }
    return strongest_armor;
}