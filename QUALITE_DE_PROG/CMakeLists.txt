cmake_minimum_required(VERSION 3.24.2)
project(QUALITE_DE_PROG)

set(CMAKE_CXX_STANDARD 17)

add_executable(QUALITE_DE_PROG main.cpp
        character.cpp
        character.h
        player.cpp
        player.h
        monster.cpp
        monster.h
        blindMonster.cpp
        blindMonster.h
        notBlindMonster.cpp
        notBlindMonster.h
        GameElement.cpp
        GameElement.h
        point.cpp
        point.h)
