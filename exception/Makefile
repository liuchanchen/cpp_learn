CC=g++
BIN=exception.bin
CFLAGS=-std=c++11
SRC=$(wildcard *.cpp)

all:${BIN}

${BIN}:
	${CC} ${CFLAGS} ${SRC} -o $@

clean:
	rm *.o ${BIN}
