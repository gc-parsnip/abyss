#ifndef __LOOTTESTS_HPP__
#define __LOOTTESTS_HPP__

#include "gtest/gtest.h"
#include "../header/loot.hpp"
#include "../header/attack_pot.hpp"
#include "../header/health_pot.hpp"
#include "../header/combo_pot.hpp"
#include "../header/weapon.hpp"

TEST(AttackPotTest, AttackZero){
    Loot* testPot = new attack_pot(0, "A bright orange pool");
    EXPECT_EQ(testPot->use(), 0);
}

TEST(AttackPotTest, AttackBelowZero){
    Loot* testPot = new attack_pot(-5, "A bright yellow pool");
    EXPECT_EQ(testPot->use(), -5);
}

TEST(AttackPotTest, AttackPositive){
    Loot* testPot = new attack_pot(5, "A bright red pool");
    EXPECT_EQ(testPot->use(), 5);
}

TEST(AttackPotTest, PotString){
    Loot* testPot = new attack_pot(5, "A pool of shimmering red liquid");
    EXPECT_EQ(testPot->GetDescription(), "A pool of shimmering red liquid");
}

TEST(HealthPotTest, HealthZeroGain){
    Loot* testPot = new health_pot(0, "A pale yellow pool");
    EXPECT_EQ(testPot->use(), 0);
}

TEST(HealthPotTest, HealthLoss){
    Loot* testPot = new health_pot(-5, "A shining red pool");
    EXPECT_EQ(testPot->use(), -5);
}

TEST(HealthPotTest, HealthGainPositive){
    Loot* testPot = new health_pot(5, "A crystalline white pool");
    EXPECT_EQ(testPot->use(), 5);
}

TEST(HealthPotTest, PotString){
    Loot* testPot = new attack_pot(5, "A pool of shimmering white liquid");
    EXPECT_EQ(testPot->GetDescription(), "A pool of shimmering white liquid");
}

TEST(ComboPotTest, ComboAttackEight){
    Loot* testPot = new combo_pot(new attack_pot(5), new attack_pot(3), "A pool of complex colors, tending towards red");
    EXPECT_EQ(testPot->use(), 8);
}

TEST(ComboPotTest, NestedComboSeven){
    Loot* testPot = new combo_pot(new attack_pot(5), new combo_pot(new attack_pot(2), new attack_pot(0), "A complex blend of colors"));
    EXPECT_EQ(testPot->use(), 7);
}

TEST(ComboPotTest, NestedComboZero){
    Loot* testPot = new combo_pot(new combo_pot(new attack_pot(0), new attack_pot(0)), new combo_pot(new attack_pot(0), new attack_pot(0)), "An empty looking pool of water");
    EXPECT_EQ(testPot->use(), 0);
}

TEST(ComboPotTest, ComboPotString){
    Loot* testPot = new combo_pot(new combo_pot(new attack_pot(0), new attack_pot(0)), new combo_pot(new attack_pot(0), new attack_pot(0)), "An empty looking pool of water");
    EXPECT_EQ(testPot->GetDescription(), "An empty looking pool of water");
}

TEST(WeaponTest, PositiveValue){
    Loot* testWeapon = new weapon(3, "A small axe");
    EXPECT_EQ(testWeapon->use(), 3);
}

TEST(WeaponTest, ZeroValue){
    Loot* testWeapon = new weapon(0, "A small axe");
    EXPECT_EQ(testWeapon->use(), 0);
}

TEST(WeaponTest, NegativeValue){
    Loot* testWeapon = new weapon(-3, "A small axe");
    EXPECT_EQ(testWeapon->use(), -3);
}

TEST(WeaponTest, StringValue){
    Loot* testWeapon = new weapon(3, "A small axe");
    EXPECT_EQ(testWeapon->GetDescription(), "A small axe");
}

#endif
