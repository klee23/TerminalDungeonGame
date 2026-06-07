#include "CombatLoop.h"
#include "Character.h"

#include <iostream>
#include <stdexcept>

////////////////////////////////////////////////////////////////
// does combat until one of the characters dies or max combat limit reached.
void CombatLoop::doCombat(Character &char1, Character &char2) {

  int max_turns = 100;
  int counter = 0;
  while (char1.isAlive() && char2.isAlive() && counter++ < max_turns) {
    // char 1 attack char2
    char2.defend(char1.attack());
    // char 2 attack char 1
    if (char2.isAlive()) {
      char1.defend(char2.attack());
    }
  }
}



////////////////////////////////////////////////////////////////
// does combat oer a party!!
void CombatLoop::doCombat(std::vector<std::unique_ptr<Character>> &p1,
                          std::vector<std::unique_ptr<Character>> &p2) {
  for (auto &goodPlayer : p1) {
    if (goodPlayer->isAlive()) {
      Character* target = goodPlayer->selectTarget(p2);
      if(target){
        target->defend(goodPlayer->attack());
      }
    }
  }

  for (auto &badPlayer : p2) {
    if(badPlayer->isAlive()){
      Character* target = badPlayer->selectTarget(p1);
      if(target){
        target->defend(badPlayer->attack());
      }
    }
  }

  for (auto &goodPlayer : p1) {
    std::cout << goodPlayer->getStatus();
  }
  for (auto &badPlayer : p2) {
    std::cout << badPlayer->getStatus();
  }

  return;
}
