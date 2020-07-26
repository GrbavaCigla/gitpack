# gitpack ![C/C++ CI](https://github.com/GrbavaCigla/gitpack/workflows/C/C++%20CI/badge.svg)
Package manager that installs and builds repositories from git. Written in C.

## Dependencies
### Debian (Ubuntu, Mint...)
```
# apt-get install -y libgit2-dev build-essential
```
### Arch (Manjaro, Arco, EndeavourOS...)
```
# pacman -S libgit2 gcc make --needed
```
### Red Hat (Fedora, CentOS...)
```
# dnf install gcc make libgit2
```
### Gentoo
```
emerge -av sys-devel/gcc sys-devel/make dev-libs/libgit2
```

## Installation
```
make
make install
```

## Usage
**Not finished yet!**
```
gp install https://github.com/GrbavaCigla/gitpack
```

## TODO
- update
- flags
- short url (check sources.txt)
- remove
- colors
- feedback
