# Mosyo - Discord Bot in C++

This project is a simple Discord bot named Mosyo, implemented in C++ using the D++ library.

## Prerequisites

- C++17 compatible compiler
- CMake (version 3.10 or higher)
- Git
- Docker (optional, for containerized deployment)

## Setup

1. Clone the repository:
   ```
   git clone https://github.com/eveleyy/mosyo.git
   cd mosyo
   ```

2. Install the D++ library:
   ```
   git clone https://github.com/brainboxdotcc/DPP.git include/DPP
   ```

3. Create a Discord bot and get the token:
   - Go to the Discord Developer Portal (https://discord.com/developers/applications)
   - Create a new application
   - Go to the "Bot" section and create a bot
   - Copy the bot token

4. Replace "YOUR_BOT_TOKEN" in `src/main.cpp` with your actual bot token.

## Building and Running

### Using CMake:

1. Create a build directory:
   ```
   mkdir build
   cd build
   ```

2. Generate the build files:
   ```
   cmake ..
   ```

3. Build the project:
   ```
   make
   ```

4. Run the bot:
   ```
   ./mosyo
   ```

### Using Docker:

1. Build the Docker image:
   ```
   docker build -t mosyo .
   ```

2. Run the Docker container:
   ```
   docker run mosyo
   ```

## Adding Plugins

To add new functionality, create new files in the `src/plugins/` directory and implement your features as separate classes. Then, integrate them into the `Bot` class as needed.
