<a href="https://github.com/oleksandrkozlov/touch_typing">
    <img src="https://raw.githubusercontent.com/oleksandrkozlov/touch_typing/master/docs/touch-typing-logo.png" alt="Touch Typing" title="Touch Typing" align="left" height="100" />
</a>

Touch Typing
============

[![Build Status](https://travis-ci.com/oleksandrkozlov/touch_typing.svg?branch=master)](https://travis-ci.com/oleksandrkozlov/touch_typing)
[![Coverage Status](https://codecov.io/gh/oleksandrkozlov/touch_typing/branch/master/graph/badge.svg)](https://codecov.io/gh/oleksandrkozlov/touch_typing)
[![Documentation Status](https://readthedocs.org/projects/touch-typing/badge/?version=latest)](https://touch-typing.readthedocs.io)

**Touch Typing** is a pre-alpha C++ application that will help you to learn touch typing which means typing through muscle memory without using the sense of sight to find the keys.

### Build

```bash
cmake -Bbuild -H.
cmake --build build
```

### Test

```bash
cmake --build build --target test
```
### Run

```bash
./build/src/touch_typing
```

### Dependencies

* [ncurses](https://invisible-island.net/ncurses/) >= 6.2

### License
[MIT License](https://github.com/oleksandrkozlov/touch_typing/blob/master/LICENSE)

Copyright (c) 2020 Oleksandr Kozlov
