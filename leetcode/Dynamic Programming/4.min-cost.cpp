#include<iostream>
using namespace std;

int minPathSumHelper(vector<vector<int> >&grid, int row, int col, int mem[][201]){
  if(row==grid.size()-1 && col==grid[0].size()-1) return grid[row][col];
  if(row>=grid.size() || col>=grid[0].size()) return INT_MAX;
  int minCost = INT_MAX;
  if(mem[row][col]!=-1) return mem[row][col];
  minCost = min(minCost, minPathSumHelper(grid, row, col+1, mem));
  minCost = min(minCost, minPathSumHelper(grid, row+1, col, mem));
  mem[row][col] = grid[row][col] + minCost;
  return mem[row][col];
}

int minPathSum(vector<vector<int>> &grid){
  int mem[201][201];
  memset(mem, -1,201*201*sizeof (int));
  return minPathSumHelper(grid, 0,0, mem);
}

// DP
int minPathSum(vector<vector<int>> &grid){
  int mem[201][201];
  memset(mem, 0, 201*201*sizeof (int));

  int row = grid.size()-1;
  int col = grid[0].size()-1;
  mem[row][col] = grid[row][col];
  // fill all data on same row

  for(int i=col-1; i>=0; i--){
    mem[row][i] = mem[row][i+1] + grid[row][i];
  }

  for(int i=row-1; i>=0; i--){
    mem[i][col] = mem[i+1][col] + grid[i][col];
  }

  for(int i=row-1; i>=0; i--){
    for(int j=col-1; j>=0; j--){
      mem[i][j]= grid[i][j]+ min( mem[i][j+1], mem[i+1][j] );
    }
  }
  return mem[0][0];
}