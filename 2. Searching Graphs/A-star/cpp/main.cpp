#include <cmath>
#include <iostream>
#include <queue>

enum Direction {Above = 0, Right = 1, Below = 2, Left = 3};

class Compare{
  public:
    bool operator() (std::pair<int, int>a, std::pair<int, int> b){
      return a.second > b.second;
    }
};

bool validate(int index, int direction, int rows, int cols){
  bool isValid = true;
  switch (direction){
  case Above:
    // i.e. index = 3, cols = 10
    if(index < cols){ // In top row, can't go up
      isValid = false;
    }
    break;
  case Right:
    // i.e. index = 7, cols 2 => false
    if(index % (cols-1) == 0){ // In right col, can't go right
      isValid = false;
    }
    break;
  case Below:
    // i.e. index = 33, rows = 3
    if(index / cols >= rows-1){ // In bottom row, can't go up
      isValid = false;
    }
    break;
  case Left:
    // i.e. index = 40,  cols = 10 => false
    if(index % cols == 0){ // In left col, can't go left
      isValid =  false;
    }
    break;
  
  default:
    break;
  }

  return isValid;
}

int heuristic(int c1, int c2, int rows, int cols){
  int c1x = c1 % cols;
  int c1y = c1 / cols;
  int c2x = c2 % cols;
  int c2y = c2 / cols;
  return std::abs(c1x - c2x) + std::abs(c1y - c2y);
}

void aStar(int* grid, int* cameFrom, int* costSoFar, int origin, int goal, int rows, int cols){
  std::priority_queue<std::pair<int, int>, std::vector< std::pair<int,int> >, Compare> priorityQueue;
  priorityQueue.push({origin, 0});
  cameFrom[origin] = -1;
  costSoFar[origin] = 0;

  int newCost;
  int newIndex;

  while (!priorityQueue.empty()){
    std::pair<int, int> curr = priorityQueue.top();
    priorityQueue.pop();

    if(curr.first == goal){
      std::cout << "Success!\n";
      break;
    }
    
    if(validate(curr.first, Above, rows, cols)){ // Check Above
      newIndex = curr.first-cols;
      newCost = costSoFar[curr.first] + 1; // TODO - Implement true cost function / feature
      if( costSoFar[newIndex] == 0 || newCost < costSoFar[newIndex]){
        costSoFar[newIndex] = newCost;
        int priority = newCost + heuristic(newIndex, goal, rows, cols);
        std::pair<int, int> newCoord = {newIndex, priority};
        priorityQueue.push(newCoord);
        cameFrom[newCoord.first] = curr.first;
      }
    }
    if(validate(curr.first, Right, rows, cols)){ // Check Right
      newIndex = curr.first+1;
      newCost = costSoFar[curr.first] + 1;
      if( costSoFar[newIndex] == 0 || newCost < costSoFar[newIndex]){
        costSoFar[newIndex] = newCost;
        int priority = newCost + heuristic(newIndex, goal, rows, cols);
        std::pair<int, int> newCoord = {newIndex, priority};
        priorityQueue.push(newCoord);
        cameFrom[newCoord.first] = curr.first;
      }
      
    }
    if(validate(curr.first, Below, rows, cols)){ // Check Below
      newIndex = curr.first+cols;
      newCost = costSoFar[curr.first] + 1;
      if( costSoFar[newIndex] == 0 || newCost < costSoFar[newIndex]){
        costSoFar[newIndex] = newCost;
        int priority = newCost + heuristic(newIndex, goal, rows, cols);
        std::pair<int, int> newCoord = {newIndex, priority};
        priorityQueue.push(newCoord);
        cameFrom[newCoord.first] = curr.first;
      }
    }
    if(validate(curr.first, Left, rows, cols)){ // Check Left
      newIndex = curr.first-1;
      newCost = costSoFar[curr.first] + 1;
      if( costSoFar[newIndex] == 0 || newCost < costSoFar[newIndex]){
        costSoFar[newIndex] = newCost;
        int priority = newCost + heuristic(newIndex, goal, rows, cols);
        std::pair<int, int> newCoord = {newIndex, priority};
        priorityQueue.push(newCoord);
        cameFrom[newCoord.first] = curr.first;
      }
    }
  }
}

int main(){
  //printNeigh(graph);
  const int rows = 10;
  const int cols = 10;
  const int origin = 0;
  const int goal = 99;
  int grid[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  int cameFrom[100] = {0};
  int costSoFar[100] = {0};
  aStar(grid, cameFrom, costSoFar, 0, 99, 10, 10);
  int node = goal;
  int count = 0;
  while(node != origin){
    std::cout << "[ " << node << " ] ==> ";
    grid[node] = 1;
    node = cameFrom[node];
    count++;
    if (count > 1000){
      std::cout << "Your loop is broken\n";
      break;
    }
  }
  std::cout << "[ " << node << " ]\n";
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      int index = i*cols + j;
      std::cout << grid[index] << ", ";
    }
    std::cout << std::endl;
  }

    return 0;
}