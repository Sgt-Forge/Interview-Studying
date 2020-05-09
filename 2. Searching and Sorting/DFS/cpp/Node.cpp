#include "Node.h"

Node::Node(){
    this->id = -1;
}

Node::Node(int id, std::vector<int> neighbors){
    this->id = id;
    this->neighbors = neighbors;
}

Node::Node(const Node& old){
    this->id = old.id;
    this->neighbors = old.neighbors;
}

Node::~Node(){}

Node Node::operator =(const Node& old){
    this->id = old.id;
    this->neighbors = old.neighbors;

    return *this;
}