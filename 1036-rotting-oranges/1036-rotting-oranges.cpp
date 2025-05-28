class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;
    for(int i=0; i<grid.size(); i++){
      for(int j=0; j<grid[0].size(); j++){
        if(grid[i][j]==2) q.push({i,j});
      }
    }

    int count = 0;
    while(!q.empty()){
      count++;
      int level = q.size();
      for(int i=0; i<level; i++){
        pair<int,int> p = q.front();
        int x =p.first;
        int y= p.second;
        q.pop();
        //left
        if(y>0 && grid[x][y-1]==1){
          grid[x][y-1] = 2;
          q.push({x, y-1});
        }
        //right
        if(y<grid[0].size()-1 && grid[x][y+1]==1){
          grid[x][y+1] = 2;
          q.push({x, y+1});
        }
        //down
        if(x<grid.size()-1 && grid[x+1][y]==1){
          grid[x+1][y] = 2;
          q.push({x+1, y});
        }
        //up
        if(x>0 && grid[x-1][y]==1){
          grid[x-1][y] = 2;
          q.push({x-1, y});
        }
      }
    }
    for(int i=0; i<grid.size(); i++){
      for(int j=0; j<grid[0].size(); j++){
        if(grid[i][j]==1) return -1;
      }
    }

    return count>0?  count -1: count;
  }
};