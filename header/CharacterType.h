#pragma once
#include <string_view>

enum class CharacterType{
    Warrior,
    Wizard,
    Monster,
    Goblin,
    Orc
};

constexpr std::string_view toString(CharacterType type){
    switch (type)
    {
    case CharacterType::Warrior:
        return "Warrior";

    case CharacterType::Wizard:
        return "Wizard";

    case CharacterType::Monster:
        return "Monster";

    case CharacterType::Goblin:
        return "Goblin";

    case CharacterType::Orc:
        return "Orc";
    }

    return "Unknown";
}