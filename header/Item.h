#pragma once

#include "ItemType.h"

class Item{
public:
    Item(int, ItemType);
    virtual ~Item() = default;

    int getValue() const noexcept;
    ItemType getType() const noexcept;

protected:
    static int validateLTETZeroValue(int);

private:
    const int value_; 
    const ItemType type_; 

    static const int validateValue(int);

};