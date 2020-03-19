#CXX=clang++
CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -O0 -fopenmp
BIN=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all:$(OBJ)
	echo $^
	$(CXX) -o $(BIN) $^ -fopenmp

%.o: %.cpp
	$(CXX) -c  $< -o  $@ $(CXXFLAGS)

clean:
	rm -f *.o
	rm $(BIN)