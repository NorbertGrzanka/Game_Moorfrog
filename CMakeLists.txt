cmake_minimum_required(VERSION 3.1)
project(SNAKE)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

add_executable(SNAKE
        CMakeLists.txt
        main.cpp
        zaba.cpp

        plansza.cpp
        plansza.h Przeszkoda.cpp Przeszkoda.h Kloda.cpp Kloda.h Samochod.cpp Samochod.h)
# Detect and add SFML
set(SFML_PATH "C:/cpp/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)

if(SFML_FOUND)
    target_link_libraries(SNAKE sfml-graphics sfml-window sfml-audio)

endif()
