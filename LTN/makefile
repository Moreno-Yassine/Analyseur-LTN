CC=g++
CFLAGS=-W -Wall -ansi -pedantic -s -O3 -Os -std=c++11 
LDFLAGS= -lboost_system -lboost_regex
EXEC=LTN
EXECWIN=LTN.exe
SRC= $(wildcard src/*.cpp)
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
	rm $(EXEC)

remake:
	make clean
	make
 
