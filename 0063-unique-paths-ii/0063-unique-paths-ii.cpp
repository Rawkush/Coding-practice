class Solution {
public:

  int findPath(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& mem){
    int maxRow = grid.size()-1;
    int maxCol = grid[0].size()-1;

    if(row>maxRow || col>maxCol) return 0;
    if(grid[row][col]==1) return 0;
    if(row==maxRow && col == maxCol) return 1;
    if(grid[row][col]==1) return 0;
    if(mem[row][col]!=-1) return mem[row][col]; 
    int maxPaths = findPath(grid, row+1, col, mem) + findPath(grid, row, col+1, mem);
    mem[row][col]= maxPaths;
    return mem[row][col];
  } 

  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      vector<vector<int>> mem(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
      int num = findPath(obstacleGrid, 0, 0,mem);
      return num;
  }
};