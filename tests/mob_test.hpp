#ifndef __MOB_TEST_HPP__
#define __MOB_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/Mob.hpp"

TEST(mob_test, test_attack)
{
	Mob test = Mob("Test", 100, 10, "");
	EXPECT_EQ(test.get_attack(), 10);
}

TEST(mob_test, test_recover) {
	Mob test = Mob("Test", 100, 10, "");
	Mob test1 = Mob("Test1", 30, 10, "");
	test.attack(&test1);
	test1.recover();
	EXPECT_EQ(test1.get_health(), 30);
}

TEST(mob_test, test_recover_when_full_hp) 
{
	Mob test = Mob("Test", 50, 10, "");
	test.recover();
	EXPECT_EQ(test.get_health(), 50);
}

TEST(mob_test, test_recover_less_than_10)
{
	Mob test = Mob("Test", 50, 8, "");
	Mob test1 = Mob("Test1", 50, 10, "");
	test.attack(&test1);
	test1.recover();
	EXPECT_EQ(test1.get_health(), 50);
}

TEST(mob_test, test_special)
{
	Mob test = Mob("Test", 100, 5, "");
	Mob test1 = Mob("Test1", 100, 20, "");
	test1.special(&test);
	EXPECT_EQ(test.get_health(), 30);
}

#endif //__MOB_TEST_HPP__
