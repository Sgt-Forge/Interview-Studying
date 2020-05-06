#ifndef SIMPLEGRAPH_H
#define SIMPLEGRAPH_H

#include <unordered_map>
#include <vector>

class SimpleGraph {
private:
    std::unordered_map<char, std::vector<char> > edges;

public:
    SimpleGraph(std::unordered_map<char, std::vector<char> > edges);
    ~SimpleGraph();
    std::vector<char> getNeighbors(char id);
};

#endif