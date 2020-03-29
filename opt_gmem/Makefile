#CXX=clang++
CXX=g++
CXXFLAGS=-pg -g -std=c++11 -Wall -O3 -fopenmp
LINKFLAGS=-pg -fopenmp
BIN=prog

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)
ASM=$(SRC:%.cpp=%.s)

all:$(OBJ) $(ASM)
	echo $^
	$(CXX) -o $(BIN) $(OBJ) $(LINKFLAGS)

%.o: %.cpp
	$(CXX) -c  $< -o  $@ $(CXXFLAGS)
%.s: %.cpp
	$(CXX) -S  $< -o  $@ $(CXXFLAGS)

clean:
	rm -f *.o *.s *.out
	rm $(BIN)