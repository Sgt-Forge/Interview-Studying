#include "Vertex.h"

Vertex::Vertex(){
    this->id = -1;
}

Vertex::Vertex(const Vertex& old){
    this->id = old.id;
    this->cost  =  old.cost;
    this->neighbors = old.neighbors;
}

Vertex::Vertex(const int& id, const int& cost, const std::vector<int>& neighbors){
    this->id = id;
    this->cost =  cost;
    this->neighbors = neighbors;
}

Vertex::~Vertex(){}

Vertex Vertex::operator=(const Vertex& old){
    this->id = old.id;
    this->neighbors =  old.neighbors;

    return *this;
}