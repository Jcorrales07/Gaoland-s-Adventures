cmake_minimum_required(VERSION 3.22)
project(Gaoland_s_Adventures)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5.1 COMPONENTS system window graphics)

include_directories(.)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Gaoland_s_Adventures pruebaMain.cpp)
add_executable(Gaoland_s_Adventures.1 pruebaMain.cpp StartScreen.cpp StartScreen.h Menu.cpp Menu.h)
target_link_libraries(Gaoland_s_Adventures sfml-system sfml-window sfml-graphics -static)
target_link_libraries(Gaoland_s_Adventures.1 sfml-system sfml-window sfml-graphics -static)