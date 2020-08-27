# gitpack ![C/C++ CI](https://github.com/GrbavaCigla/gitpack/workflows/C/C++%20CI/badge.svg)
Package manager that installs and builds repositories from git. Written in C.  
__For Linux (and maybe Mac)__

## Dependencies
__NOTE: I use gentoo, so I don't guarantee it will work. If you find dependencies are not correct for your distribution, make issue or pull request__

### Debian (Ubuntu, Mint...)
```
# apt-get install -y libgit2-dev libtar libcurl-dev build-essential
```
### Arch (Manjaro, Arco, EndeavourOS...)
```
# pacman -S libgit2 libtar curl gcc make --needed
```
### Red Hat (Fedora, CentOS...)
```
# dnf install gcc make libgit2 libtar libcurl
```
### Gentoo (CloverOS, Funtoo...)
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
gp install GrbavaCigla/gitpack
```

## TODO
- update
- ~~flags~~
- ~~short url (check sources.txt)~~
- remove (almost done)
- colors
- feedback
