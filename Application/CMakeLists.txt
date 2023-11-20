cmake_minimum_required(VERSION 3.26)
project(Application)

set(CMAKE_CXX_STANDARD 23)

add_executable(Application
        components/header/blindMonster.h
        components/header/character.h
        components/header/GameElement.h
        components/header/monster.h
        components/header/notBlindMonster.h
        components/header/point.h

        components/src/blindMonster.cpp
        components/src/character.cpp
        components/src/GameElement.cpp
        components/src/monster.cpp
        components/src/point.cpp

        tests/testGameELement.cpp
        tests/testpoint.cpp
        tests/doctest.h
        tests/testmonstre.cpp
        tests/testing.cpp
)
