CC=g++
CFLAGS=-W -Wall -ansi -pedantic -s -O3 -Os
LDFLAGS=
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

clean:
	rm -rf src/*.o
	rm -rf $(EXEC)
	rm -rf $(EXECWIN)
 