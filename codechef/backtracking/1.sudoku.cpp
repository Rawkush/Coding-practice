#include <iostream>
#include <vector>
using namespace std;
#define N 9

bool findEmptyLocation(int grid[N][N], int row, int col){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(grid[i][j]==0){
        row=i;
        col=j;
        return true;
      }
    }
  }
  return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
  // check in row
  for(int i=0; i< N; i++){
    if(grid[row][i]==num) return false;
  }

  // check in the same column
  for(int i=0; i< N; i++){
    if(grid[i][col]==num) return false;
  }

  // check in 3X3 cell
  int rowFactor = row-(row%3);
  int colFactor = col-(col%3);
  for(int i=rowFactor; i<rowFactor+3; i++){
    for(int j=colFactor; j<colFactor+3; j++){
      if(grid[i][j]==num) return false;
    }
  }
  return true;
}

bool solveSudoku(int grid[N][N]){
  int row, col;
  if(!findEmptyLocation(grid, row, col)){
    return true;
  }
  for(int i=1; i<=N; i++){
    if(isSafe(grid, row, col, i)){
      grid[row][col] = i;
      if(solveSudoku(grid)) return true;
      grid[row][col] = 0;
    }
  }
  return false;
}

int main(){
  int grid[N][N];
  for (int i = 0; i < N; i++){
    string s;
    cin >> s;
    for (int j = 0; j < N; j++){
      grid[i][j] = s[j] - '0';
    }
  }
  solveSudoku(grid);
  return 0;
}