#include <gtest/gtest.h>

#include "Character.h"
#include "Orc.h"

TEST(CharacterTest, isAlive_Test){

    Orc player("Orc", 100, 12);
    EXPECT_TRUE(player.isAlive());

}

TEST(CharacterTest, negative_damage_test){

    Orc player("Orc", 100, 12);
    EXPECT_THROW(player.defend(-5), std::invalid_argument); 
}


TEST(CharacterTest, damage_test){

    Orc player("Orc", 100, 12);
    player.defend(5);
    EXPECT_TRUE(player.getHealth()==95); 
}