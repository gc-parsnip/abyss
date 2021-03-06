#include "gtest/gtest.h"

#include "LootTests.hpp"
#include "player_test.hpp"
#include "mob_test.hpp"
#include "floor_test.hpp"
#include "MobBuilderTest.hpp"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
