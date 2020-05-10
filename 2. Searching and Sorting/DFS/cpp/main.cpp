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

std::vector<int> DFS(const std::vector<Vertex>& graph, int goal){
    Heap frontier;
    frontier.push(graph.at(0)); // assume 0 is origin
    std::vector<int> cameFrom(graph.size());

    while( !frontier.empty()){
        Vertex curr = frontier.pop();
        if (curr.getId() == goal){
            std::cout << "Success!\n" ;
            break;
        }

        auto neighb = curr.getNeighbors();
        for(auto it = neighb.begin(); it != neighb.end(); ++it){
            int newId = *it;
            if ( cameFrom[newId-1] == 0){
                frontier.push(graph.at(newId-1));
                cameFrom[newId-1] = curr.getId();
            }
        }
    }

    return cameFrom;
}

int main(){
    const Vertex n0(1, {3,4});
    const Vertex n1(2, {4,5});
    const Vertex n2(3, {1,6});
    const Vertex n3(4, {2,5,6,7});
    const Vertex n4(5, {2,4});
    const Vertex n5(6, {2,4,7,8});
    const Vertex n6(7, {4,6,8});
    const Vertex n7(8, {6,7});
    std::vector<Vertex> graph = {n0, n1, n2, n3, n4, n5, n6, n7};
    //printNeigh(graph);
    std::vector<int> paths = DFS(graph, 8);
    int node = 8;
    int count = 0;
    while(node != 1){
        std::cout << "[ " << node << " ] ==>" ;
        node = paths[node-1];
        ++count;
        if (count > 1000){
            std::cout << "[ERROR]\tYour loop is broken has is running infinitely!" << std::endl;
            break;
        }
    }
    std::cout << "[ " << node << " ]" << std::endl;

    return 0;
}