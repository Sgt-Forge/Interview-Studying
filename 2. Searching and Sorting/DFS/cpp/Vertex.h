#ifndef VERTEX_H 
 #define VERTEX_H

#include <vector>

class Vertex{
private:
    int id;
    std::vector<int> neighbors;
    
public:
    Vertex();
    Vertex(int id, std::vector<int> neighbors);
    Vertex(const Vertex& old);
    ~Vertex();

    Vertex operator =(const Vertex&);
    
    inline void setId(int id){ this->id = id; }
    inline void setNeighbors(std::vector<int>& neighbors){ this->neighbors = neighbors; }
    inline int getId(){ return this->id; };
    inline std::vector<int> getNeighbors(){ return this->neighbors; };
};

#endif