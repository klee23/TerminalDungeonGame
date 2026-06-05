#include <gtest/gtest.h>

#include "Wizard.h"
#include "Character.h"
#include "Monster.h"


TEST(WizardTest, cast_spell_attack_test){

    Monster player("Monster", 100, 12,2,4);
    Wizard wizard("Wizard", 100, 5, 10);
    //wizard.CastSpell();
    EXPECT_TRUE(wizard.GetMana()==9);
    player.defend(wizard.attack());
    EXPECT_TRUE(player.getHealth()==95);

}