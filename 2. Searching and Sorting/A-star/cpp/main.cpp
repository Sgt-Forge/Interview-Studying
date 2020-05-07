#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
// #include <bits/stdc++.h>

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const std::pair<T1, T2>& p) const{
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};


void printGrid(std::vector< std::vector<int> > grid){
  std::cout << "=============== GRID ===============\n";
  for(auto it = grid.begin(); it != grid.end(); ++it){
    for(auto inner = (*it).begin(); inner != (*it).end(); ++inner){
      std::cout << *inner << ", ";
    }
    std::cout << "\n" ;
  }
  std::cout << "=============== GRID ===============\n";
}

bool isValidCord(std::pair<int, int> cord, int maxX, int maxY){
  bool ret = false;
  if (cord.first >= 0 && cord.first < maxX){
    if (cord.second >= 0 && cord.second < maxY){
      ret = true;
    }
  }
  return ret;
}

void aStar(){
    
}

int BFS(std::vector< std::vector<int> > grid){
  std::queue<std::pair<int, int>> frontier;
  std::pair<int, int> origin = {0, 0};
  std::pair<int, int> goal = {-1, -1};
  std::unordered_map< std::pair<int, int>, int, hash_pair> cameFrom;

  frontier.push(origin);
  while(!frontier.empty()){
    std::pair<int, int> current = frontier.front();
    frontier.pop();
    std::cout << "x:\t" << current.first << std::endl;
    std::cout << "y:\t" << current.second << std::endl;
    if( grid[current.first][current.second] == 9){
      std::cout << "[DBG]:\tFound the goal!" << std::endl;
      goal.first = current.first;
      goal.second = current.second;
      cameFrom[goal] = 1 + cameFrom[current];
    }

    std::pair<int, int> left (current.first-1, current.second);
    std::pair<int, int> top = {current.first, current.second+1};
    std::pair<int, int> right = {current.first+1, current.second};
    std::pair<int, int> bottom = {current.first, current.second-1};
    if (isValidCord(left, grid.size(), grid[0].size()) && !cameFrom[left]){
      frontier.push(left);
      cameFrom[left] = cameFrom[current]; 
    } 
    if (isValidCord(top, grid.size(), grid[0].size()) && !cameFrom[top]){
      frontier.push(top);
      cameFrom[top] = 1 + cameFrom[current];
    }
    if (isValidCord(right, grid.size(), grid[0].size()) && !cameFrom[right]){
      frontier.push(right);
      cameFrom[right] = 1 + cameFrom[current];
    }
    if (isValidCord(bottom, grid.size(), grid[0].size()) && !cameFrom[bottom]){
      frontier.push(bottom);
      cameFrom[bottom] = 1 + cameFrom[current];
    }
  }

  return cameFrom[goal];
}

int main(int argc, char* argv[]){
  std::vector< std::vector<int> > grid = {{1, 0, 0}, {1, 0 , 0}, {1, 9, 0}};
  printGrid(grid);
  std::cout << "=====================================\n";
  std::cout << BFS(grid) << std::endl;

    return 0;
}