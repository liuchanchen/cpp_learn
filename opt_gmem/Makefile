#CXX=clang++
CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -O3 -fopenmp
BIN=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)
ASM=$(SRC:%.cpp=%.s)

all:$(OBJ) $(ASM)
	echo $^
	$(CXX) -o $(BIN) $(OBJ) -fopenmp

%.o: %.cpp
	$(CXX) -c  $< -o  $@ $(CXXFLAGS)
%.s: %.cpp
	$(CXX) -S  $< -o  $@ $(CXXFLAGS)

clean:
	rm -f *.o *.s
	rm $(BIN)