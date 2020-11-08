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
    pkg-config \
    python3 \
    libdocopt-dev \
    # docs
    graphviz \
    doxygen \
    # kcov
    binutils-dev \
    libcurl4-openssl-dev \
    zlib1g-dev \
    libdw-dev \
    libiberty-dev \
    # codecov
    curl \
    # cmake-format
    python3-pip

RUN pip3 install \
    cmakelang \
    sphinx \
    sphinx_rtd_theme \
    breathe

RUN git clone --depth=1 --branch v37 \
    https://github.com/SimonKagstrom/kcov.git kcov \
    && cmake -Hkcov -Bkcov/build -GNinja -DCMAKE_BUILD_TYPE=Release \
    && cmake --build kcov/build --target install --parallel

RUN git clone --depth=1 --branch clang_10 \
    https://github.com/include-what-you-use/include-what-you-use.git iwyu \
    && cmake -Hiwyu -Biwyu/build -GNinja -DCMAKE_BUILD_TYPE=Release \
    && cmake --build iwyu/build --target install --parallel
