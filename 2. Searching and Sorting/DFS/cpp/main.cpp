#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "Node.h"

void printNeigh(std::vector<Node> graph){
    for(auto it = graph.begin(); it != graph.end(); ++it){
        std::vector<int> currNeigh = (*it).getNeighbors();
        std::cout << "Current node:\t" << (*it).getId() << "|\tNeighbors:\t";
        for(auto itNode = currNeigh.begin(); itNode != currNeigh.end(); ++itNode){
            std::cout << (*itNode) << ", " ;
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
    const Node n0(0, {2,3});
    const Node n1(1, {3,4});
    const Node n2(2, {0,5});
    const Node n3(3, {1,4,5,6});
    const Node n4(4, {1,3});
    const Node n5(5, {2,3,6,7});
    const Node n6(6, {3,5,7});
    const Node n7(7, {5,6});
    std::vector<Node> nodes = {n0, n1, n2, n3, n4, n5, n6, n7};
    printNeigh(nodes);

    return 0;
}