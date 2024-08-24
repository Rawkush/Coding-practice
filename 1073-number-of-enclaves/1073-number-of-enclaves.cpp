class Solution {
public:
    int countEnclaves(vector<vector<int>>& grid, queue<pair<int, int>>& q,
                      vector<vector<bool>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            // top
            if (row>0 && grid[row-1][col]==1 && !vis[row-1][col]){
                vis[row-1][col]= true;
                q.push({row-1, col});
            }
            //down
            if (row<m-1 && grid[row+1][col]==1 && !vis[row+1][col]){
                vis[row+1][col]= true;
                q.push({row+1, col});
            }
            //left
            if (col>0 && grid[row][col-1]==1 && !vis[row][col-1]){
                vis[row][col-1]= true;
                q.push({row, col-1});
            }
            //right

            if (col<n-1 && grid[row][col+1]==1 && !vis[row][col+1]){
                vis[row][col+1]= true;
                q.push({row, col+1});
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]==1)count++;
            }
        }

        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        // up and bottom rows
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                vis[0][i] = true;
                q.push({0, i});
            }
            if (grid[m - 1][i] == 1) {
                vis[m - 1][i] = true;
                q.push({m - 1, i});
            }
        }
        // first and last col
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                vis[i][0] = true;
                q.push({i, 0});
            }
            if (grid[i][n - 1] == 1) {
                vis[i][n - 1] = true;
                q.push({i, n - 1});
            }
        }
        return countEnclaves(grid, q, vis);
    }
};