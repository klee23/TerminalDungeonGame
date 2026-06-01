#include <gtest/gtest.h>

#include "Character.h"

TEST(CharacterTest, isAlive_Test){

    Character player("Player", 100, 12);
    EXPECT_TRUE(player.isAlive());

}

TEST(CharacterTest, negative_damage_test){

    Character player("Player", 100, 12);
    EXPECT_THROW(player.takeDamage(-5), std::invalid_argument); 
}


TEST(CharacterTest, damage_test){

    Character player("Player", 100, 12);
    player.takeDamage(5);
    EXPECT_TRUE(player.getHealth()==95); 
}