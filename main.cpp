#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

#include "Character.h"
#include "CombatLoop.h"

int main(int, char**){
    std::cout << "Hello, from TerminalDungeonGame!\n";

    Character player("Player", 100, 12);
    Character monster("Monster",75, 5);

    CombatLoop combat_loop;
    try{
        combat_loop.doCombat(player, monster);
        std::cout << player.getStatus() ;
        std::cout << monster.getStatus() ;
    
    } catch(std::runtime_error& e){
        std::cerr << e.what() << std::endl;
    }
    catch(...){
        std::cerr << "CAUGHT unknown error." << std::endl;
    }

}
