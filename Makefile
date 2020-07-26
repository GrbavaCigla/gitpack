CC=cc
NAME=gp

CONFIG_DIR = $(HOME)/.config/gitpack/
CACHE_DIR = $(HOME)/.cache/gitpack/

COMMAND_FILE = $(CONFIG_DIR)build.sh
# SOURCES_FILE = $(CONFIG_DIR)sources.txt

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

INC = $(shell pkg-config --cflags libgit2)
LIB = $(shell pkg-config --libs libgit2)

_CFLAGS = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -O3
VARS = -DCONFIG_DIR=\"${CONFIG_DIR}\" -DCACHE_DIR=\"${CACHE_DIR}\" -DCOMMAND_FILE=\"${COMMAND_FILE}\"

CFLAGS  = $(VARS) $(_CFLAGS) $(INC)
LDFLAGS = $(LIB)

SRC=$(wildcard src/*.c) $(wildcard src/*.h)
OBJ = ${SRC:src/%.c=obj/%.o}

obj/%.o: $(SRC)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/gp: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJ)

install: obj/gp
	install -t $(PREFIX)/bin/ -D obj/gp

