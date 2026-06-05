#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Character.h"
#include "Goblin.h"
#include "Orc.h"
#include "Warrior.h"
#include "Monster.h"
#include "CombatLoop.h"
#include "Wizard.h"

int main(int, char**){
    std::cout << "Hello, from TerminalDungeonGame!\n";

    Warrior player("Player", 100, 12, 1);
    Monster monster("Monster",75, 5, 2, 3);

    std::cout << "Combat1! \n";
    CombatLoop combat_loop;
    try{
        combat_loop.doCombat(player, monster);
        std::cout << player.getStatus() ;
        std::cout << monster.getStatus() ;
    
    } catch(std::runtime_error& e){
        std::cerr << e.what() << std::endl;
    } catch(...){
        std::cerr << "CAUGHT unknown error." << std::endl;
    }

    std::cout << "Combat2! \n";
    std::vector<std::unique_ptr<Character>> goodParty;
    goodParty.push_back(std::make_unique<Warrior>("Warrior",100,10,5));
    goodParty.push_back(std::make_unique<Wizard>("TheWiz", 100, 5, 10));

    std::vector<std::unique_ptr<Character>> evilParty;
    evilParty.push_back(std::make_unique<Orc>("Orc", 200, 5));
    evilParty.push_back(std::make_unique<Monster>("MonStar", 100,5,5,2));
    evilParty.push_back(std::make_unique<Goblin>("Gobz",100,2,2,2,2));

    try{
        combat_loop.doCombat(goodParty, evilParty);
    }  catch(...){
        std::cerr << "CAUGHT error." << std::endl;
    }

}
