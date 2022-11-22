![Touch Typing](https://repository-images.githubusercontent.com/254851395/15050e80-0b0f-11eb-946c-fcf11540dae4)

<a href="https://github.com/oleksandrkozlov/touch_typing">
    <img src="https://raw.githubusercontent.com/oleksandrkozlov/touch_typing/master/docs/touch-typing-logo.png" alt="Touch Typing" title="Touch Typing" align="left" height="100" />
</a>

Touch Typing
============

[![Build Status](https://travis-ci.com/oleksandrkozlov/touch_typing.svg?branch=master)](https://travis-ci.com/oleksandrkozlov/touch_typing)
[![Coverage Status](https://codecov.io/gh/oleksandrkozlov/touch_typing/branch/master/graph/badge.svg)](https://codecov.io/gh/oleksandrkozlov/touch_typing)
[![Documentation Status](https://readthedocs.org/projects/touch-typing/badge/?version=latest)](https://touch-typing.readthedocs.io)
[![Coverity Status](https://scan.coverity.com/projects/22300/badge.svg)](https://scan.coverity.com/projects/oleksandrkozlov-touch_typing)

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

* [CMake](https://cmake.org)
* [GSL](https://github.com/microsoft/GSL)
* [Ncurses](https://invisible-island.net/ncurses/)
* [docopt.cpp](https://github.com/docopt/docopt.cpp)
* [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/)
* [spdlog](https://github.com/gabime/spdlog)
* [{fmt}](https://fmt.dev/)

### Development Dependencies

* [Breathe](https://breathe.readthedocs.io)
* [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/)
* [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html)
* [Conventional Commits](https://www.conventionalcommits.org)
* [Cppcheck](http://cppcheck.sourceforge.net)
* [Doxygen](https://www.doxygen.nl)
* [Google Test](https://github.com/google/googletest)
* [Graphviz](https://graphviz.org)
* [Kcov](http://simonkagstrom.github.io/kcov/)
* [Ninja](https://ninja-build.org)
* [Python](https://www.python.org)
* [Read the Docs Sphinx Theme](https://sphinx-rtd-theme.readthedocs.io)
* [Sphinx](https://www.sphinx-doc.org)
* [ccache](https://ccache.dev)
* [cmake language tools](https://cmake-format.readthedocs.io)
* [include-what-you-use](https://include-what-you-use.org)

### Continuous Integration Dependencies

* [Codecov](https://codecov.io)
* [Docker](https://www.docker.com)
* [Git](https://git-scm.com)
* [Node.js](https://nodejs.org)
* [Read the Docs](https://readthedocs.org)
* [Ruby](https://www.ruby-lang.org)
* [commitlint](https://commitlint.js.org)
* [curl](https://curl.haxx.se)
* [nmp](https://www.npmjs.com)

### Roadmap

- [ ] Integrate [Conan](https://conan.io/).
- [ ] Add GUI.
- [ ] Switch to C++20 (e.g, modules).

### License

[MIT License](https://github.com/oleksandrkozlov/touch_typing/blob/master/LICENSE), Copyright (c) 2020 Oleksandr Kozlov
