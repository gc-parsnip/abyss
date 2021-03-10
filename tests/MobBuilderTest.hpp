#ifndef __MOBBUILDERTEST_HPP__
#define __MOBBUILDERTEST_HPP__

#include "gtest/gtest.h"
#include "../header/basic_unit.hpp"
#include "../header/Mob.hpp"
#include "../header/mob_builder.hpp"
#include "../header/basic_mob_builder.hpp"
#include "../header/normal_weapon_builder.hpp"

TEST(MobBuilderTest, mobMade) {
    basic_mob_builder mobBuilder;
    Mob* test = mobBuilder.GetMob(1);
    bool mobMade = false;
    if(test != nullptr) mobMade = true;
    EXPECT_EQ(mobMade, true);
}

TEST(MobBuilderTest, mobName) {
    basic_mob_builder mobBuilder;
    Mob* test = mobBuilder.GetMob(1);
    EXPECT_EQ(test->get_name(), "Slime");
}

TEST(MobBuilderTest, mobDescription) {
    basic_mob_builder mobBuilder;
    Mob* test = mobBuilder.GetMob(1);
    EXPECT_EQ(test->getMobDescription(), "It's bouncing at you. Menacingly!");
}

TEST(WeaponBuilderTest, weaponMade) {
    normal_weapon_builder weaponBuilder;
    weapon* madeWeapon = weaponBuilder.GetWeapon(1);
    bool isWeapon = false;
    if(madeWeapon != nullptr) isWeapon = true;
    EXPECT_EQ(isWeapon, true);
}

TEST(WeaponBuilderTest, weaponHasDescription) {
    normal_weapon_builder weaponBuilder;
    weapon* madeWeapon = weaponBuilder.GetWeapon(1);
    EXPECT_EQ(madeWeapon->GetDescription(), "A small handmade knife.");
}

#endif
