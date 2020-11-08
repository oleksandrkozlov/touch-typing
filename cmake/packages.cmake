find_package(PkgConfig 0.29 REQUIRED)
find_package(docopt 0.6)
find_package(fmt 6.1 REQUIRED)
pkg_check_modules(ncurses REQUIRED IMPORTED_TARGET ncurses>=6.2)
