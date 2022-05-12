cmake_minimum_required(VERSION 3.22)
project(Gaoland_s_Adventures)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "/home/shello/Programs/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1
        COMPONENTS
        system window graphics network audio REQUIRED)

include_directories(.)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(gao-app main.cpp revolverGame.cpp revolverGame.h)
add_executable(gao-app.1 pruebaMain.cpp StartScreen.cpp StartScreen.h Menu.cpp Menu.h)
target_link_libraries(Gaoland_s_Adventures sfml-system sfml-window sfml-graphics -static)
target_link_libraries(Gaoland_s_Adventures.1 sfml-system sfml-window sfml-graphics -static)