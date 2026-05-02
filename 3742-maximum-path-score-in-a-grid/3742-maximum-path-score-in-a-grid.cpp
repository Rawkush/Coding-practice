class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if(i>=grid.size() || j>=grid[0].size() || k<0) return -1;
        int pk=k;
        if(dp[i][j][k]!=-2) return dp[i][j][k];
        if(grid[i][j]>0) {
            k--;
        }
        if(k<0) return -1;
        if(i==grid.size()-1 && j == grid[0].size()-1) return dp[i][j][pk]= grid[i][j]; 
        // if(i==grid.size()-1 && j == grid[0].size()-1) return -1;
        int r = helper(grid, i, j+1, k, dp);
        int b = helper(grid, i+1, j, k, dp);
        return dp[i][j][pk] = max(b,r) >= 0 ? max(r,b) + grid[i][j]: -1;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k+1, -2)));
        return helper(grid, 0, 0, k, dp);
    }
};