CXX = g++
INC_DIR = ./include
SRC_DIR = ./src
CXXFLAGS = -c -Wall -O2 -I$(INC_DIR)
INCLUDES = $(INC_DIR)/*.hpp

main: build/main.o build/ff.o
	$(CXX) build/main.o build/ff.o -o main

main_bipartite: build/main_bipartite.o build/bipartite.o
	$(CXX) build/main_bipartite.o build/bipartite.o build/ff.o -o main_bipartite

build/%.o: $(SRC_DIR)/%.cpp $(INCLUDES) 
	$(CXX) $(CXXFLAGS) $< -o $@
