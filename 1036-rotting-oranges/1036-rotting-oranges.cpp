class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        //push all rotten oranges to queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2) q.push({i , j});
            }
        }

        int t=0;
        // BFS
        while(!q.empty()){
            t++;
            int s = q.size();
            for(int k=0; k<s; k++){
                pair<int, int> p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();
                //up
                if(i>0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({ i-1, j});
                }
                // down
                if(i<m-1 && grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                }
                //left
                if(j>0 && grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                }
                //right
                if(j<n-1 && grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                }
            }
        }

        // check if any fresh orange is remaining
           for(int i=0; i<grid.size(); i++){
            for(int j=0; j< grid[0].size(); j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return t>0? t-1: t;     
    }
};