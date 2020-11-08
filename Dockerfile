FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    clang-9 \
    clang-format \
    clang-tidy \
    cmake \
    cppcheck \
    curl \
    doxygen \
    graphviz \
    iwyu \
    kcov \
    libdocopt-dev \
    libfmt-dev \
    libgtest-dev \
    ninja-build \
    pkg-config \
    python3 \
    python3-pip

RUN pip3 install \
    breathe \
    cmakelang \
    sphinx \
    sphinx_rtd_theme
