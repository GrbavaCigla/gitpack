#!/bin/sh

if test $(command -v sudo); then 
    set SUCMD = sudo
elif test $(command -v doas); then
    set SUCMD = doas
fi

cd "${PKGPATH}"

if [ -f "configure" ]; then
    ./configure
fi

if [ -f "CMakeLists.txt" ]; then
    echo "CMAKE detected"
    mkdir build
    cd build
    cmake ..
fi

if [ -f "Makefile" ]; then
	make
	${SUCMD} make install
fi
