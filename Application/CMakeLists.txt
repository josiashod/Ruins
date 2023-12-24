cmake_minimum_required(VERSION 3.26)
project(Application)

set(CMAKE_CXX_STANDARD 23)

add_executable(Application tests/testing.cpp
        components/header/adventurer.h
        components/header/armor.h
        components/header/blindMonster.h
        components/header/box.h
        components/header/castle.h
        components/header/character.h
        components/header/coord.h
        components/header/equipment.h
        components/header/monster.h
        components/header/sword.h

        components/src/adventurer.cpp
        components/src/armor.cpp
        components/src/blindMonster.cpp
        components/src/box.cpp
        components/src/castle.cpp
        components/src/character.cpp
        components/src/coord.cpp
        components/src/equipment.cpp
        components/src/monster.cpp
        components/src/sword.cpp

        tests/doctest.h
        tests/testobject.cpp
        tests/testpoint.cpp
        tests/test_box.cpp
        tests/testadventurer.cpp
        tests/testblindmonster.cpp
        tests/testmonster.cpp
)
