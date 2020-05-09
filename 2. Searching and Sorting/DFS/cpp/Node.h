#ifndef NODE_H
#define NODE_H

#include <vector>

class Node{
private:
    int id;
    std::vector<int> neighbors;
    
public:
    Node();
    Node(int id, std::vector<int> neighbors);
    ~Node();
    
    inline void setId(int id){ this->id = id; }
    inline void setNeighbors(std::vector<int>& neighbors){ this->neighbors = neighbors; }
    inline int getId(){ return this->id; };
    inline std::vector<int> getNeighbors(){ return this->neighbors; };
};

#endif