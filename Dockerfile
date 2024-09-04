# Build stage
FROM gcc:latest AS build

# Install CMake and other dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    libssl-dev \
    libopus-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the source code and CMakeLists.txt
COPY . .

# Create a build directory and build the project
RUN mkdir build && cd build && \
    cmake .. && \
    make

# Runtime stage
FROM debian:buster-slim

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libssl1.1 \
    libopus0 \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the built executable from the build stage
COPY --from=build /app/build/discord-bot .

# Set the command to run the bot
CMD ["./discord-bot"]
