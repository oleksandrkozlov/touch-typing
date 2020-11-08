![Touch Typing](https://repository-images.githubusercontent.com/254851395/15050e80-0b0f-11eb-946c-fcf11540dae4)

<a href="https://github.com/oleksandrkozlov/touch_typing">
    <img src="https://raw.githubusercontent.com/oleksandrkozlov/touch_typing/master/docs/touch-typing-logo.png" alt="Touch Typing" title="Touch Typing" align="left" height="100" />
</a>

Touch Typing
============

[![Build Status](https://travis-ci.com/oleksandrkozlov/touch_typing.svg?branch=master)](https://travis-ci.com/oleksandrkozlov/touch_typing)
[![Coverage Status](https://codecov.io/gh/oleksandrkozlov/touch_typing/branch/master/graph/badge.svg)](https://codecov.io/gh/oleksandrkozlov/touch_typing)
[![Documentation Status](https://readthedocs.org/projects/touch-typing/badge/?version=latest)](https://touch-typing.readthedocs.io)

**Touch Typing** is a pre-alpha C++ application that will help you to learn touch typing which means typing through muscle memory without using the sense of sight to find the keys.

### Demo

[![asciicast](https://asciinema.org/a/364545.svg)](https://asciinema.org/a/364545)

### Configure

```
cmake -Bbuild -H. -DCMAKE_BUILD_TYPE=Release
```

### Build

```
cmake --build build --parallel
```

### Test

```
cmake --build build --target test
```

### Install

```
cmake --build build --target install
```

### Run

```
touch_typing
```

### Dependencies

* [CMake](https://cmake.org) >= 3.16
* [Ncurses](https://invisible-island.net/ncurses/) >= 6.2
* [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/) >= 0.29

### Development Dependencies

* [Breathe](https://breathe.readthedocs.io) >= 4.22
* [Clang-Tidy](https://releases.llvm.org/10.0.0/tools/clang/tools/extra/docs/clang-tidy/) >= 10.0
* [ClangFormat](https://releases.llvm.org/10.0.0/tools/clang/docs/ClangFormat.html) >= 10.0
* [Conventional Commits](https://www.conventionalcommits.org) >= 1.0
* [Cppcheck](http://cppcheck.sourceforge.net) >= 1.90
* [Doxygen](https://www.doxygen.nl) >= 1.8
* [Google Test](https://github.com/google/googletest) >= 1.10
* [Graphviz](https://graphviz.org) >= 2.42
* [Kcov](http://simonkagstrom.github.io/kcov/) >= 37.0
* [Ninja](https://ninja-build.org) >= 1.10
* [Python](https://www.python.org) >= 3.8
* [Read the Docs Sphinx Theme](https://sphinx-rtd-theme.readthedocs.io) >= 0.5
* [Sphinx](https://www.sphinx-doc.org) >= 3.2
* [cmake language tools](https://cmake-format.readthedocs.io) >= 0.6
* [docopt.cpp](https://github.com/docopt/docopt.cpp) >= 0.6
* [include-what-you-use](https://include-what-you-use.org) >= 0.14

### Continuous Integration Dependencies

* [Bundler](https://bundler.io) >= 2.1
* [Codecov](https://codecov.io)
* [Danger](https://danger.systems/ruby) >= 8.0
* [Docker](https://www.docker.com) > 18.6
* [Git](https://git-scm.com) >= 2.25
* [Node.js](https://nodejs.org) >= 8.12
* [Read the Docs](https://readthedocs.org)
* [Ruby](https://www.ruby-lang.org) >= 2.5
* [commitlint](https://commitlint.js.org) >= 8.3
* [curl](https://curl.haxx.se) >= 7.68
* [nmp](https://www.npmjs.com) >= 6.14

### License

[MIT License](https://github.com/oleksandrkozlov/touch_typing/blob/master/LICENSE), Copyright (c) 2020 Oleksandr Kozlov
