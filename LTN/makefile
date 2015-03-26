CC=g++
CFLAGS=-W -Wall -ansi -pedantic -s -O3 -Os -std=c++11 -fpermissive
LDFLAGS= -lboost_system -lboost_regex

SRCDIR=src
HEADDIR=include
LIBDIR=build
BINDIR=bin

BIN=LTN
SRC=$(shell find . -name '*.cpp')
TMP=$(subst $(SRCDIR),$(LIBDIR), $(SRC))
OBJ=$(patsubst %.cpp,%.o,$(TMP))

all: $(BIN)

LTN: $(OBJ)
	@[ ! -d $(BINDIR) ] & mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)/$@ $^ $(LDFLAGS)

$(LIBDIR)/%.o: $(SRCDIR)/%.cpp
	@[ ! -d $(dir $@) ] & mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY = clean

# Nettoyage des objets => Tout sera recompiler !
clean:
	rm $(LIBDIR)/*.o
	rm $(LIBDIR)/*/*.o
	rm $(LIBDIR)/*/*/*.o
	rm $(BINDIR)/*
