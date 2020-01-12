#CXX=clang++
CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -O3
BIN=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all:$(OBJ)
	echo $^
	$(CXX) -o $(BIN) $^

%.o: %.cpp
	$(CXX) -c  $< -o  $@ $(CXXFLAGS)

clean:
	rm -f *.o
	rm $(BIN)