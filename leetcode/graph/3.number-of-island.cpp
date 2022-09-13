  void helper(vector<vector<char>> &grid, int row, int col){
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
    if(grid[row][col]=='0') return;
    if(grid[row][col]=='1'){
      grid[row][col] ='0';
      helper(grid, row-1, col);
      helper(grid, row+1, col);
      helper(grid, row, col+1);
      helper(grid, row, col-1);
    }
    return;
  }

  int numIslands(vector<vector<char>> &grid){
    int count=0;
    for(int i=0; i<grid.size(); i++){
      for(int j=0; j<grid[0].size(); j++){
        if(grid[i][j]=='0') continue;
        count++;
        cout<<", i: "<<i<<" j: "<<j;
        helper(grid, i, j);
      }
    }
    return count;
  }
