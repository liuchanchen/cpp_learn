CC=g++
BIN=exception.bin
CFLAGS=-std=c++11
SRC=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp, %.o, $(SRC))

all:${BIN}
${BIN}:$(OBJS)
	${CC} -o $@ $(OBJS)  
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o ${BIN}
