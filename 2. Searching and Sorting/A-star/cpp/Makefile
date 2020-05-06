# ================================
CXX = g++
CXXFLAGS = -Wall -pedantic -g
OBJECTS = main.o SimpleGraph.o
# ================================

main: $(OBJECTS)
	$(CXX) -o main $(CXXFLAGS) $(OBJECTS)

main.o: SimpleGraph.h
SimpleGraph.o: SimpleGraph.h

.PHONY: clean
clean:
	rm main $(OBJECTS)