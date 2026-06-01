#include "CombatLoop.h"
#include <stdexcept>

////////////////////////////////////////////////////////////////
// does combat until one of the characters die....
void CombatLoop::doCombat(Character& char1, Character& char2){
    
    int counter = 0;
    while( char1.isAlive() && char2.isAlive() ){
        // char 1 attack char2
        char2.takeDamage(char1.getAttackDamage() );
        // char 2 attack char 1
        if(char2.isAlive() ){
            char1.takeDamage(char2.getAttackDamage());
        }
        // combat limit.
        if(counter++ > 10000){
            throw std::runtime_error("BAD!, Max combat limit reached! Exiting combat");
            break;
        }
    }

}

