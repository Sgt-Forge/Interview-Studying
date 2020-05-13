CXX = g++
CXXFLAGS = -Wall -g -pedantic
OBJECTS = main.o Vertex.o Heap.o

main: $(OBJECTS)
	$(CXX) -o main $(CXXFLAGS) $(OBJECTS)

main.o: Vertex.h
Vertex.o: Vertex.h
Heap.o: Heap.h Vertex.h

.PHONY: clean
clean:
	rm main $(OBJECTS)