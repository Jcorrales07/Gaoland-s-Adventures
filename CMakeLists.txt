cmake_minimum_required(VERSION 3.22)
project(Gaoland_s_Adventures)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5.1 COMPONENTS system window graphics audio)

include_directories(.)

set(SOURCE
        Animation.cpp
        Animation.h
        main.cpp
        MenuScreen.cpp
        MenuScreen.h
        Options.cpp
        Options.h
        StartScreen.cpp
        StartScreen.h
        Ruleta.cpp
        Ruleta.h
        Theme.cpp
        Theme.h
        ArtTheme.cpp
        ArtTheme.h
        BadCar.cpp
        BadCar.h
        Car.cpp
        Car.h
        Introduction.cpp
        Introduction.h
        LuckyCoin.cpp
        LuckyCoin.h
        MarioKart.cpp
        MarioKart.h
        MysteryBoxes.cpp
        MysteryBoxes.h
        SmashBros.cpp
        SmashBros.h)

add_executable(Gaoland_s_Adventures ${SOURCE})
target_link_libraries(Gaoland_s_Adventures sfml-system sfml-window sfml-graphics sfml-audio -static)