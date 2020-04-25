CXX = g++
CXXFLAGS = -c -Wall -O2 -I include

kosaraju: build/kosaraju/main.o build/kosaraju/scc.o
	$(CXX) build/kosaraju/main.o build/kosaraju/scc.o -o main_kosaraju

dcsc: build/dcsc/main.o build/dcsc/scc.o
	$(CXX) build/dcsc/main.o build/dcsc/scc.o -o main_dcsc

build/kosaraju/%.o: src/kosaraju/%.cpp include/kosaraju/scc.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

build/dcsc/%.o: src/dcsc/%.cpp include/dcsc/scc.hpp
	$(CXX) $(CXXFLAGS) $< -o $@
