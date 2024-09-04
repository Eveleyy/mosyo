cmake_minimum_required(VERSION 3.10)
project(mosyo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set OpenSSL paths
set(OPENSSL_ROOT_DIR "/opt/homebrew/opt/openssl@3")
set(OPENSSL_INCLUDE_DIR "/opt/homebrew/opt/openssl@3/include")
set(OPENSSL_CRYPTO_LIBRARY "/opt/homebrew/opt/openssl@3/lib/libcrypto.dylib")
set(OPENSSL_SSL_LIBRARY "/opt/homebrew/opt/openssl@3/lib/libssl.dylib")

find_package(OpenSSL REQUIRED)

# Add the D++ library
add_subdirectory(include/DPP)

# Add the source files
add_executable(mosyo
    src/main.cpp
    src/Bot.cpp
)

# Link the D++ library
target_link_libraries(mosyo PRIVATE dpp)

