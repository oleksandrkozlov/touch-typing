FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    git \
    llvm-dev \
    libclang-dev \
    clang \
    clang-format \
    clang-tidy \
    ninja-build \
    cmake \
    cppcheck \
    libgtest-dev \
    # kcov
    binutils-dev \
    libcurl4-openssl-dev \
    zlib1g-dev \
    libdw-dev \
    libiberty-dev \
    python3 \
    # codecov
    curl

RUN git clone --depth=1 https://github.com/SimonKagstrom/kcov.git kcov \
    && cmake -Hkcov -Bkcov/build -GNinja -DCMAKE_BUILD_TYPE=Release \
    && cmake --build kcov/build --target install --parallel
