cmake_minimum_required(VERSION 3.20)
project(jeuechec C)

set(CMAKE_C_STANDARD 11)

# Pour Homebrew (Apple Silicon)
set(CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(jeuechec
        fonction.c
        main.c
)

target_link_libraries(jeuechec
        SDL2::SDL2
        SDL2_image::SDL2_image
)