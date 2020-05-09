#include "Heap.h"

Heap::Heap(){}
Heap::Heap(std::vector<Node> nodes){
    std::vector<Node> temp = nodes;
    this->head = *(temp.begin());
    temp.erase(temp.begin());
    this->nodes = temp;
}
Heap::~Heap(){}

Node Heap::pop(){
    Node temp = this->head;
    Node head = *(nodes.begin());
    this->nodes.erase(nodes.begin());
    
    return temp;
}
void Heap::push(){}