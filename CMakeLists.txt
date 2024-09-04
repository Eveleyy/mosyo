cmake_minimum_required(VERSION 3.10)
project(mosyo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the D++ library
add_subdirectory(include/DPP)

# Add the source files
add_executable(mosyo
    src/main.cpp
    src/Bot.cpp
)

# Link the D++ library
target_link_libraries(mosyo PRIVATE dpp)
