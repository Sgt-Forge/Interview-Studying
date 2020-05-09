CXX = g++
CXXFLAGS = -Wall -g -pedantic
OBJECTS = main.o Node.o

main: $(OBJECTS)
	$(CXX) -o main $(CXXFLAGS) $(OBJECTS)

main.o: Node.h
Node.o: Node.h

.PHONY: clean
clean:
	rm main $(OBJECTS)