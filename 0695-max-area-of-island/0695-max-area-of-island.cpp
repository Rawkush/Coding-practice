class Solution {
public:
    //recursive
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&vis) {
        if(i>= grid.size() || j>=grid[0].size()) return 0;
        if(vis[i][j]!=-1) return 0;
        vis[i][j] = 1;
        if(grid[i][j]==0) return 0;
        int c = helper(grid, i,j+1, vis);
        c += helper(grid, i+1,j, vis);
        c += helper(grid, i-1,j, vis);
        c += helper(grid, i,j-1, vis);
        return vis[i][j] = c+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
        int mx = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                mx = max(mx, helper(grid, i, j, vis));
            }
        }

        return mx;
    }
};