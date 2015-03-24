CC=g++
CFLAGS=-W -Wall -ansi -pedantic -s -O3 -Os -std=c++11 -fpermissive
LDFLAGS= -lboost_system -lboost_regex

# Les différents répertoires contenant respectivement les fichiers : Sources *.c, Headers *.h, Objets *.o, l'exécutable
SRCDIR=src
HEADDIR=include
LIBDIR=build
BINDIR=bin

BIN=LTN
SRC= $(wildcard src/*.cpp src/symboles/*.cpp src/etats/*.cpp src/symboles/symboles_elementaires/*.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(BIN)

LTN: $(OBJ)
	$(CC) -o $(BINDIR)/$@ $^ $(LDFLAGS)

# Création des différents *.o à partir des *.cpp
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HEADDIR)/%.h
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY = clean

# Nettoyage des objets => Tout sera recompiler !
clean:
	rm $(LIBDIR)/*.o
	rm ./src/*.o
	rm ./src/*/*.o
	rm ./src/*/*/*.o

# Nettoyage complet => clean + effacement du l'exécutable
Clean: clean
	rm $(BINDIR)/*
