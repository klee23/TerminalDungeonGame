#pragma once

#include "ItemType.h"

class Item{
public:
    Item(int, ItemType);
    ~Item() = default;

    const int getValue() noexcept;
    const ItemType getType() noexcept;

private:
    int value_; // const?
    ItemType type_; // const?

    static const int validateValue(int);
};