#include "SimpleGraph.h"

SimpleGraph::SimpleGraph(std::unordered_map<char, std::vector<char> > edges){
    this->edges = edges;
}

std::vector<char> SimpleGraph::getNeighbors(char id){
    return this->edges[id];
}