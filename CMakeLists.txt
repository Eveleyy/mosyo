cmake_minimum_required(VERSION 3.15)
project(mosyo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenSSL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPUS REQUIRED opus)

# Add D++ library
add_subdirectory(include/DPP)

# Add your source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the executable
add_executable(mosyo ${SOURCES})

# Include directories
target_include_directories(mosyo PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${OPUS_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(mosyo 
    PRIVATE 
    ${OPENSSL_LIBRARIES}
    ${OPUS_LIBRARIES}
    dpp
)

# Print debug information
message(STATUS "OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message(STATUS "OpenSSL libraries: ${OPENSSL_LIBRARIES}")
message(STATUS "Opus include dirs: ${OPUS_INCLUDE_DIRS}")
message(STATUS "Opus libraries: ${OPUS_LIBRARIES}")

enable_testing()
add_test(NAME MosyoTest COMMAND mosyo test)
