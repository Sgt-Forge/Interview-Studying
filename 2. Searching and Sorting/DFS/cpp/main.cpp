#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "Heap.h"

void printNeigh(std::vector<Vertex> graph){
    for(auto it = graph.begin(); it != graph.end(); ++it){
        std::vector<int> currNeigh = (*it).getNeighbors();
        std::cout << "Current node:\t" << (*it).getId() << "|\tNeighbors:\t";
        for(auto itVertex = currNeigh.begin(); itVertex != currNeigh.end(); ++itVertex){
            std::cout << (*itVertex) << ", " ;
        }
        std::cout << std::endl;
    }
}

int DFS(std::unordered_map<int, std::vector<int> > grid){
    std::vector< std::vector<int> > frontier;
    std::unordered_map<int, int> came_from;
    frontier.push_back(grid[0]);

    while(!frontier.empty()){
        auto current = frontier.front();
    }

    return 0;
}

int main(){
    const Vertex n0(0, {2,3});
    const Vertex n1(1, {3,4});
    const Vertex n2(2, {0,5});
    const Vertex n3(3, {1,4,5,6});
    const Vertex n4(4, {1,3});
    const Vertex n5(5, {2,3,6,7});
    const Vertex n6(6, {3,5,7});
    const Vertex n7(7, {5,6});
    //std::vector<Vertex> nodes = {n0, n1, n2, n3, n4};
    //printNeigh(nodes);
    Heap heap;
    heap.push(n0);
    heap.push(n1);
    heap.push(n2);
    heap.push(n3);
    heap.push(n4);
    std::cout << heap.pop().getId() << std::endl;
    std::cout << heap.pop().getId() << std::endl;
    std::cout << heap.pop().getId() << std::endl;
    heap.push(n5);
    heap.push(n6);
    heap.push(n7);
    std::cout << heap.pop().getId() << std::endl;
    std::cout << heap.pop().getId() << std::endl;
    std::cout << heap.pop().getId() << std::endl;

    return 0;
}