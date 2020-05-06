#include <iostream>
#include "SimpleGraph.h"

int main(int argc, char* argv[]){
    std::unordered_map<char, std::vector<char> > edges = std::unordered_map<char, std::vector<char> >({{
    {'A', {'B'}},
    {'B', {'A', 'C', 'D'}},
    {'C', {'A'}},
    {'D', {'E', 'A'}},
    {'E', {'B'}}
  }});

    for(auto i = edges.begin(); i != edges.end(); i++){
        std::cout << "First:\t" << i->first << "Second.size()" << i->second.size() << std::endl;
    }

    return 0;
}