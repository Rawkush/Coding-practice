class Solution {
public:

  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> pq;
    // vector<vector<int>> isVisited(grid.size(), vector<int>(grid[0].size(), 0))
    //push all rotten oranges
    for(int i=0; i<grid.size(); i++){
      for(int j=0; j<grid[i].size(); j++){
        if(grid[i][j]==2){
          pq.push({i, j});
        }
      }
    }    

    int rsize = grid.size()-1;
    int csize = grid[0].size()-1;
    int time =-1;
    while(!pq.empty()){
      int s = pq.size(); 
      time++;
      for(int i=0; i<s; i++){
        pair<int, int> cor = pq.front();
        pq.pop();
        int row = cor.first;
        int col = cor.second;

        // up
        if(row!=0 && grid[row-1][col]==1){
          pq.push({row-1, col});
          grid[row-1][col]=2;
        }

        //right
        if(col!=csize && grid[row][col+1]==1){
          pq.push({row, col+1});
          grid[row][col+1]=2;
        }

        //left
        if(col!=0 && grid[row][col-1]==1){
          pq.push({row, col-1});
          grid[row][col-1]=2;
        }

        //bottom

        if(row!=rsize && grid[row+1][col]==1){
          pq.push({row+1, col});
          grid[row+1][col]=2;
        }

      }
    }

    for(int i=0; i<grid.size(); i++){
      for(int j=0; j<grid[i].size(); j++){
        if(grid[i][j]==1){
          return -1;
        }
      }
    } 
    if(time ==-1) return 0;
    return time;
  }
};