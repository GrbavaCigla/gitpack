CC=cc
NAME=gp

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

INC = $(shell pkg-config --cflags libgit2)
LIB = $(shell pkg-config --libs libgit2)

_CFLAGS = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Wno-nonnull -O3

CFLAGS  = $(VARS) $(_CFLAGS) $(INC)
LDFLAGS = $(LIB)

SRC=$(wildcard src/*.c) $(wildcard src/*.h)
OBJ = ${SRC:src/%.c=obj/%.o}

obj/%.o: $(SRC)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/${NAME}: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJ)

install: obj/${NAME}
	install -t $(PREFIX)/bin/ -D obj/${NAME}
	mkdir -p $(shell grep "config_path" src/config.h | grep -oE "\".+\"" | tr -d \" | tr -d ";")
	mkdir -p ${shell grep "cache_path" src/config.h | grep -oE "\".+\"" | tr -d \" | tr -d ";"}
	cp res/build.sh ${shell grep "cmdlist_path" src/config.h | grep -oE "\".+\"" | tr -d \" | tr -d ";"}

