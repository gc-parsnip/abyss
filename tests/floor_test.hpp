#ifndef __FLOOR_TEST_HPP__
#define __FLOOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/floor_builder.hpp"
#include "../header/director.hpp"
#include "../header/normal_floor_builder.hpp"
#include "../header/floors.hpp"
#include <iostream>
#include <cstdlib>

TEST(floor_test, CheckFloorExists) {
    Player test1 = Player("test", 100, 25);
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(0, &test1);
    EXPECT_EQ(floor != nullptr, true);
    EXPECT_EQ(floor->displayFloorDescription(), "Forest\r\nA vast forest expands out and reaches as far as the eye can see. \r\nThere is a small dirt trail that leads deep into the forest.\r\nIt seems like this is the only path forward.\r\n");
}

TEST(floor_test, BuildNormalForestFloor) {
    Player test1 = Player("test", 100, 25);
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(0, &test1);
    EXPECT_EQ(floor->displayFloorDescription(), "Forest\r\nA vast forest expands out and reaches as far as the eye can see. \r\nThere is a small dirt trail that leads deep into the forest.\r\nIt seems like this is the only path forward.\r\n");
}

TEST(floor_test, BuildNormalCanyonFloor) {
    Player test1 = Player("test", 100, 25);
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(2, &test1);
    EXPECT_EQ(floor->displayFloorDescription(), "Canyon\r\nDry rocks and dust blow in the wind across gigantic cliff faces.\r\nIt is a beautiful yet harsh landscape. \r\nThe way forward is uncertain.\r\n");
}

TEST(floor_test, CheckFloorLootGT) {
    Player test1 = Player("test", 100, 25);
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(1, &test1);
    Loot* temp  = floor->getLoot();
    std::cout << temp->GetDescription() << std::endl;
    EXPECT_GT(temp->use(), -1);
}

TEST(floor_test, CheckFloorLootLT) {
    Player test1 = Player("test", 100, 25);
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(1, &test1);
    Loot* temp  = floor->getLoot();
    std::cout << temp->GetDescription() << std::endl;
    EXPECT_LT(temp->use(), 11);
}

TEST(floor_test, CheckFloorMob) {
    Player test1 = Player("test", 100, 25);
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(1, &test1);
    std::vector<Mob*> temp = floor->getMobs();
    EXPECT_EQ(temp.at(0)->get_name(), "Slime");
}


TEST(floor_test, AttackFloorMob) {
    Player test1 = Player("test", 100, 25);
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(1, &test1);
    std::vector<Mob*> temp = floor->getMobs();
    test1.attack(temp.at(0));
    EXPECT_EQ(temp.at(0)->get_health(), -24);
}

TEST(floor_test, CheckFloorLootWeapon) {
    Player test1 = Player("test", 100, 25);
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(1, &test1);
    Loot* temp = floor->getLoot();
    std::cout << temp->GetDescription() << std::endl;
}




#endif