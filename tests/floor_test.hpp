#ifndef __FLOOR_TEST_HPP__
#define __FLOOR_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/floor_builder.hpp"
#include "../header/director.hpp"
#include "../header/normal_floor_builder.hpp"
#include "../header/floors.hpp"

TEST(floor_test, BuildNormalFloor) {
    Normal_Floor_Builder nf;
    Director test(&nf);
    Floor* floor = test.generateFloor(0);
    EXPECT_EQ(floor->displayFloorDescription(), "hello");
}


#endif