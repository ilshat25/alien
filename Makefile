CXX 		:= g++
CXX_FLAGS 	:= -std=c++17 -ggdb -Wall -Wextra

BIN 		:= bin
SRC 		:= src src/entities src/base
INCLUDE 	:= include

LIBRARIES 	:= -lncurses
EXECUTABLE 	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(foreach d, $(SRC), $d/*.cpp)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*

build:	clean all
