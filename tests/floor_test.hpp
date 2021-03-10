#ifndef __FLOOR_TEST_HPP__
#define __FLOOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/floor_builder.hpp"
#include "../header/director.hpp"
#include "../header/normal_floor_builder.hpp"
#include "../header/floors.hpp"
#include <iostream>

TEST(floor_test, BuildNormalForestFloor) {
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(0);
    EXPECT_EQ(floor->displayFloorDescription(), "Forest\r\nA vast forest expands out and reaches as far as the eye can see. \r\nThere is a small dirt trail that leads deep into the forest.\r\nIt seems like this is the only path forward.\r\n");
}

TEST(floor_test, BuildNormalCanyonFloor) {
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(2);
    EXPECT_EQ(floor->displayFloorDescription(), "Canyon\r\nDry rocks and dust blow in the wind across gigantic cliff faces.\r\nIt is a beautiful yet harsh landscape. \r\nThe way forward is uncertain.\r\n");
}

TEST(floor_test, CheckFloorLootGT) {
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(1);
    Loot* temp  = floor->getLoot();
    EXPECT_GT(temp->use(), -1);
}

TEST(floor_test, CheckFloorLootLT) {
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(1);
    Loot* temp  = floor->getLoot();
    EXPECT_LT(temp->use(), 11);
}



#endif