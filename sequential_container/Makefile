#CXX=clang++
CXX=g++
CXXFLAGS=-g -std=c++11 -Wall 
BIN=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all:$(OBJ)
	echo $^
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o *.s
	rm $(BIN)