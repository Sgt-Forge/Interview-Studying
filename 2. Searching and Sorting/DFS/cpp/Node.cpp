#include "Node.h"

Node::Node(){
    this->id = -1;
}

Node::Node(int id, std::vector<int> neighbors){
    this->id = id;
    this->neighbors = neighbors;
}
