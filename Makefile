CC=g++
CFLAGS=-O2
SRC=$(wildcard src/*.cpp)

main: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	del main.exe
