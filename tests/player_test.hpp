#ifndef __PLAYER_TEST_HPP__
#define __PLAYER_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/player.hpp"
#include "../header/weapon.hpp"

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

TEST(player_test, test_recover) {
    Player test = Player("Test", 100, 10);
    Player test1 = Player("Test1", 30, 10);
    test.attack(&test1);
    test1.recover();
    EXPECT_EQ(test1.get_health(), 30);
}

TEST(player_test, test_recover_when_full_hp) {
    Player test = Player("Test", 50, 10);
    test.recover();
    EXPECT_EQ(test.get_health(), 50);
}

TEST(player_test, test_increment_attack) {
    Player test = Player("Test", 100, 10);
    test.increment_attack(20);
    EXPECT_EQ(test.get_attack(), 30);
}

TEST(player_test, test_increment_health) {
    Player test = Player("Test", 50, 10);
    test.increment_health(50);
    EXPECT_EQ(test.get_health(), 100);
}

TEST(player_test, test_increment_health_after_taking_damage) {
    Player test = Player("Test", 50, 10);
    Player test1 = Player("Test1", 50, 30);
    test1.attack(&test);
    test.increment_health(50);
    EXPECT_EQ(test.get_health(), 70);
}

TEST(player_test, test_increment_score) {
    Player test = Player("Test", 100, 5); 
    test.increment_score();
    EXPECT_EQ(test.get_score(), 1);
}

TEST(player_test, test_increment_score_twice) {
    Player test = Player("Test", 100, 5);
    test.increment_score();
    test.increment_score();
    EXPECT_EQ(test.get_score(), 2);
}

TEST(player_test, test_special_attack) {
    Player test = Player("Test", 100, 5);
    Player test1 = Player("Test1", 100, 20);
    test1.special(&test);
    EXPECT_EQ(test.get_health(), 30);
}

TEST(player_test, test_inspect_hp) {
    Player test = Player("Test", 100, 50);
    Player test1 = Player("Test", 500, 20);
    EXPECT_EQ(test.inspect_hp(&test1), 500);
}




#endif 