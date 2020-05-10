#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <unordered_map>

class Vertex{
private:
    int id;
    std::vector<int> cost;
    std::vector<int> neighbors;

public:
    Vertex();
    Vertex(const int&, const std::vector<int>&, const std::vector<int>&);
    Vertex(const Vertex&);
    ~Vertex();

    Vertex operator  =(const Vertex&);

    inline int getId(){ return this->id; }
    inline std::vector<int> getCost(){ return this->cost; }
    inline std::vector<int> getNeighbors(){ return this->neighbors; }
    inline void setId(int id){ this->id = id; }
    inline void setCost(std::vector<int> cost){ this->cost =  cost; }
    inline void setNeighbors(std::vector<int>& neighbors){ this->neighbors = neighbors; }
};

#endif