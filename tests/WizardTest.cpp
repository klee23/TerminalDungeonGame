#include <gtest/gtest.h>

#include "Wizard.h"
#include "Character.h"


TEST(WizardTest, cast_spell_attack_test){

    Character player("Player", 100, 12);
    Wizard wizard("Wizard", 100, 5, 10);
    wizard.CastSpell();
    EXPECT_TRUE(wizard.GetMana()==9);
    player.takeDamage(wizard.getAttackDamage());
    EXPECT_TRUE(player.getHealth()==95);

}