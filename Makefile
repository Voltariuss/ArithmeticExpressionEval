CC=g++
CFLAGS=-O2
SRC=$(wildcard src/*.cpp) $(wildcard include/*.cpp)

main: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	del main.exe
