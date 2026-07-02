class Solution {
public:

    bool helper(vector<vector<int>>& grid, int health, int i, int j,  vector<vector<int>>& vis,  vector<vector<vector<int>>> &dp) {
        if(i==grid.size()-1 && j == grid[0].size()-1) {
            return (health - grid[i][j]) > 0;
        }
        if(health <0) return false;
        if(dp[i][j][health]!=-1) return dp[i][j][health] ==1;
        if(vis[i][j]==1) return false;
        vis[i][j] = 1;
        
        int newHealth  = health - grid[i][j];
        bool ans = false;
        if(j+1 < grid[0].size()) {
            ans = ans || helper(grid, newHealth, i, j+1, vis, dp);
        }
        if(j-1>=0) {
            ans = ans || helper(grid, newHealth, i, j-1, vis, dp);
        }
        
        if(i+1 < grid.size()) {
            ans = ans || helper(grid, newHealth, i+1, j, vis, dp);
        }
        
        if(i-1>=0) {
            ans = ans || helper(grid, newHealth, i-1, j, vis, dp);
        }
        vis[i][j] = 0;
        dp[i][j][health] = ans ? 1 : 0;
        return ans;
    }


    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>( health+1,-1)));
        return helper(grid, health, 0, 0, vis, dp);
    }
};