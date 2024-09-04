# Build stage
FROM gcc:12 AS build

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
FROM debian:bookworm-slim

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libssl3 \
    libopus0 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy the built executable and libraries from the build stage
COPY --from=build /app/build/mosyo .
COPY --from=build /app/build/include/DPP/library/libdpp.so* /usr/local/lib/
COPY --from=build /app/include/DPP /usr/local/include/DPP

# Set the library path
ENV LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

# Run ldconfig to update the shared library cache
RUN ldconfig

# Copy the token file (assuming it's in the project root)
COPY token .

# Run the bot
CMD ["./mosyo", "token"]
