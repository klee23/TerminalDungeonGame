#pragma once

#include "Item.h"

#include <vector>
#include <memory>

class Inventory{
public:
    Inventory(int);
    // no copy
    Inventory(const Inventory& i) = delete;
    Inventory& operator=(const Inventory& i) = delete;
    // no move
    Inventory(Inventory&& i) = delete;
    Inventory& operator=(Inventory&& i) = delete;

    bool addItem(std::unique_ptr<Item>&&);
    std::unique_ptr<Item> getItem();

private:
    int maxCapacity_;
    
    std::vector<std::unique_ptr<Item>> inventory_;

    static const int validateMaxCapacity(int);

};