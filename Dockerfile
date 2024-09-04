# Build stage
FROM gcc:latest AS build

# Install CMake and other dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    libssl-dev \
    libopus-dev \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the entire project
COPY . .

# Create a build directory and build the project
RUN mkdir build && cd build && \
    cmake -DCMAKE_BUILD_TYPE=Debug .. && \
    make

# Runtime stage
FROM debian:buster-slim

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libssl1.1 \
    libopus0 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy the built executable from the build stage
COPY --from=build /app/build/mosyo .

# Copy the token file (assuming it's in the project root)
COPY token .

# Run the bot
CMD ["./mosyo", "token"]
