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
    libgtest-dev
