#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int DFS(std::unordered_map<int, std::vector<int> > grid){

    return 0;
}

int main(){
    std::unordered_map<int, std::vector<int> > grid = {
        {0, {2, 3}},
        {1, {3, 4}},
        {2, {0, 5}},
        {3, {1, 4, 5, 6}},
        {4, {1, 3}},
        {5, {2, 3, 6, 7}},
        {6, {3, 5, 7}},
        {7, {5, 6}},
    };
    for (auto it = grid.begin(); it != grid.end(); ++it){
        std::cout << (*it).first << std::endl;
    }

    return 0;
}