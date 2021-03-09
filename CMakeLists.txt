CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
	tests/test.cpp
    src/Mob.cpp
    src/player.cpp
    src/attack_pot.cpp
    src/health_pot.cpp
    src/basic_mob_builder.cpp
    src/normal_weapon_builder.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
