cmake_minimum_required(VERSION 3.26)
project(Application)

set(CMAKE_CXX_STANDARD 23)

add_executable(Application tests/testing.cpp
        components/header/point.h
        components/header/GameElement.h
        components/header/character.h
        components/header/monster.h
        components/header/blindMonster.h
        components/header/notBlindMonster.h
        components/header/object.h
        components/header/sword.h
        components/header/armor.h

        components/src/point.cpp
        components/src/GameElement.cpp
        components/src/character.cpp
        components/src/player.cpp
        components/src/monster.cpp
        components/src/blindMonster.cpp
        components/src/notBlindMonster.cpp
        components/src/object.cpp
        components/src/sword.cpp
        components/src/armor.cpp

        tests/doctest.h
        tests/testpoint.cpp
        tests/testGameELement.cpp
        tests/testmonstre.cpp
        tests/testobject.cpp
)
