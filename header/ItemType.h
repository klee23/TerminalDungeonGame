#pragma once

#include <string_view>

enum class ItemType{
    Weapon,
    Potion,
    Money,
    Junk,
    Armor,
    Food
};

constexpr std::string_view toString(ItemType type){
    switch (type){
    case ItemType::Weapon:
        return "Weapon";

    case ItemType::Potion:
        return "Potion";

    case ItemType::Money:
        return "Money";
    
    case ItemType::Junk:
        return "Junk";
    
    case ItemType::Food:
        return "Food";

    case ItemType::Armor:
        return "Armor";

    }// switch

    return "Unknown";
};