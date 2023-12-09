cmake_minimum_required(VERSION 3.24.2)
project(Application)

set(CMAKE_CXX_STANDARD 23)

add_executable(Application tests/testing.cpp
        components/header/coord.h
        components/header/character.h
        components/header/adventurer.h
        components/header/monster.h
        components/header/blindMonster.h
        components/header/equipment.h
        components/header/sword.h
        components/header/armor.h
        components/header/case.h

        components/src/coord.cpp
        components/src/character.cpp
        components/src/adventurer.cpp
        components/src/monster.cpp
        components/src/blindMonster.cpp
        components/src/equipment.cpp
        components/src/sword.cpp
        components/src/armor.cpp
        components/src/case.cpp

        tests/doctest.h
        tests/testpoint.cpp
        tests/testmonstre.cpp
        tests/testobject.cpp components/src/case.cpp components/header/case.h)
