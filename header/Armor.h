#pragma once

#include "Item.h"

class Armor : public Item {

public:
  Armor(int, int);

  int getDefenseValue() const;

private:
    const int defenseValue_;
};