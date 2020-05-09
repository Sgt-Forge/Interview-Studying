#include "Vertex.h"

Vertex::Vertex(){
    this->id = -1;
}

Vertex::Vertex(int id, std::vector<int> neighbors){
    this->id = id;
    this->neighbors = neighbors;
}

Vertex::Vertex(const Vertex& old){
    this->id = old.id;
    this->neighbors = old.neighbors;
}

Vertex::~Vertex(){}

Vertex Vertex::operator =(const Vertex& old){
    this->id = old.id;
    this->neighbors = old.neighbors;

    return *this;
}