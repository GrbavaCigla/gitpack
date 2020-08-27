#!/bin/sh

#if test $(command -v sudo); then 
#    set SUCMD = sudo
#    echo "Using sudo"
#elif test $(command -v doas); then
#    set SUCMD = doas
#    echo "Using doas"
#fi

cd "${PKGPATH}"

if [ -f "configure" ]; then
    ./configure
fi

if [ -f "CMakeLists.txt" ]; then
    mkdir build
    cd build
    cmake ..
fi

if [ -f "Makefile" ] || [ -f "makefile" ]; then
	make
	make install
fi

if [ -f "meson.build" ]; then
	mkdir build
	meson build
	cd build
	ninja
	ninja install
fi
