#pragma once

#include "Item.h"

class Weapon : public Item{

public:
    Weapon(int,int);

    int getAttackValue() const;
private:
    int attackValue_;
};