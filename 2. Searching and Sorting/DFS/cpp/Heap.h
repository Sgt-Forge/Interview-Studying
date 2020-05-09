#ifndef HEAP_H
#define HEAP_H

#include <vector>

#include "Node.h"

class Heap{
private:
    std::vector<Node> nodes;
    Node head;

public:
    Heap();
    Heap(std::vector<Node> nodes);
    ~Heap();

    void setNodes(std::vector<int> nodes);
    inline std::vector<Node> getNodes(){ return this->nodes;}

    Node pop();
    void push();
};

#endif