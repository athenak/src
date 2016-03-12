cmake_minimum_required(VERSION 3.3)
project(powerGrid)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Cities.cpp
    Cities.h
    Coal.cpp
    Coal.h
    Country.cpp
    Country.h
    GamePlay.cpp
    GamePlay.h
    Garbage.cpp
    Garbage.h
    Houses.cpp
    Houses.h
    main.cpp
    Money.cpp
    Money.h
    Oil.cpp
    Oil.h
    Payments.cpp
    Payments.h
    Player.cpp
    Player.h
    PlayerOrder.cpp
    PlayerOrder.h
    PowerPlant.cpp
    PowerPlant.h
    Resources.cpp
    Resources.h
    Uranium.cpp
    Uranium.h)

add_executable(powerGrid ${SOURCE_FILES})