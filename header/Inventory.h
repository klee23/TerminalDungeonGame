#pragma once

#include "Armor.h"
#include "Item.h"
#include "ItemType.h"

#include <optional>
#include <vector>
#include <memory>
#include "Weapon.h"

class Inventory{
public:
    Inventory(int);
    // no copy
    Inventory(const Inventory& i) = delete;
    Inventory& operator=(const Inventory& i) = delete;
    // no move // TODO, maybe allow moves.
    Inventory(Inventory&& i) = delete;
    Inventory& operator=(Inventory&& i) = delete;

    bool addItem(std::unique_ptr<Item>&&);

    std::optional<size_t> findFirstItemType(ItemType type) const;
    std::unique_ptr<Item> extractItemById(int id);

    Item* getStrongestPotion();
    Weapon* getStrongestWeapon() const;
    Armor* getStrongestArmor() const;

private:
    int maxCapacity_;
    
    std::vector<std::unique_ptr<Item>> inventory_;

    static const int validateMaxCapacity(int);

};