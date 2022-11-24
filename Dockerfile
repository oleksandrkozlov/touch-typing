FROM ubuntu:22.10

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    ccache \
    clang \
    clang-format \
    clang-tidy \
    cmake \
    cppcheck \
    curl \
    doxygen \
    git \
    graphviz \
    iwyu \
    kcov \
    libc++-dev \
    libc++abi-15-dev \
    libdocopt-dev \
    libfmt-dev \
    libgtest-dev \
    libmsgsl-dev \
    libspdlog-dev \
    ninja-build \
    pkg-config \
    python3 \
    python3-pip

RUN pip3 install \
    breathe \
    cmakelang \
    sphinx \
    sphinx_rtd_theme
