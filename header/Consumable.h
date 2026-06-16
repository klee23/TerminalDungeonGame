#pragma once
#include "Item.h"

class Consumable : public Item{

public:
    Consumable(int, int);

    inline int getCosumerValue() const;

private:
    const int consumeValue_;
};