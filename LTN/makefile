CC=g++
CFLAGS=-W -Wall -ansi -pedantic -s -O3 -Os -std=c++11 -fpermissive
LDFLAGS= -lboost_system -lboost_regex
EXEC=LTN
EXECWIN=LTN.exe
SRC= $(wildcard src/*.cpp src/symboles/*.cpp src/etats/*.cpp src/symboles/symboles_elementaires/*.cpp)
OBJ= $(SRC:.cpp=.o)
 
all: $(EXEC)
 
LTN: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
 
%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY = clean

cleanWin:
	rm ./src/*.o
	rm $(EXECWIN)

clean:
	rm ./src/*.o
	rm ./src/*/*.o
	rm ./src/*/*/*.o
	rm $(EXEC)

remake:
	make clean
	make
 
