#ifndef __PLAYER_TEST_HPP__
#define __PLAYER_TEST_HPP__

#include "gtest/gtest.h"
#include "Player.hpp"

TEST(player_test, test_get_health) {
    Player test = Player("Test", 100, 10);
    EXPECT_EQ(test.get_health(), 100);
}

TEST(player_test, test_get_attack) {
    Player test = Player("Test", 100, 10);
    EXPECT_EQ(test.get_attack(), 10);
}

TEST(player_test, test_attack) {
    Player test = Player("Test", 100, 10);
    Player test1 = Player("Test1", 50, 10);
    test.attack(&test1);
    EXPECT_EQ(test1.get_health(), 40);
}

#endif 