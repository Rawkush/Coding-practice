class DisjointSet {
    public:
    unordered_map<int,int> parent, size;
    int mx = 0;
    int findP(int n) {
        if(parent.find(n)==parent.end()){ 
            size[n] = 1;    // A new node starts with 1 vertex
            mx = max(mx, 1);
            return parent[n]=n;
        }
        if(n==parent[n]) return n;
        return parent[n] = findP(parent[n]); // path compression
    }

    void unionBySize(int u, int v) {
        int p1 = findP(u);
        int p2 = findP(v);
        if(p1==p2) return;
        if(size[p2] > size[p1]) swap(p1, p2);
        size[p1]+=size[p2];
        parent[p2] = p1;
        mx = max(mx, size[p1]);
    }
    int getMax() {
        return mx;
    }
};
class Solution {
public:
    // assume if 2D array was 1D array then 
    // idx can be caluclated
    int convertPointsToIdx(int i, int j, int m) {
        return i*m + j;
    }
    //Union Find
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        DisjointSet ds;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0) continue;
                int currentVertex = convertPointsToIdx(i, j, m);
                ds.findP(currentVertex);
                if(j+1<grid[0].size() && grid[i][j+1]) {
                    int right_neighbor = convertPointsToIdx(i, j+1, m);
                    ds.unionBySize(currentVertex, right_neighbor);
                }
                if(i+1<n && grid[i+1][j]) {
                    int bottom_neighbor = convertPointsToIdx(i+1, j, m);
                    ds.unionBySize(currentVertex, bottom_neighbor);
                }
            }
        }

        return ds.getMax();
    }



    //recursive
    // int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&vis) {
    //     if(i>= grid.size() || j>=grid[0].size()) return 0;
    //     if(vis[i][j]!=-1) return 0;
    //     vis[i][j] = 1;
    //     if(grid[i][j]==0) return 0;
    //     int c = helper(grid, i,j+1, vis);
    //     c += helper(grid, i+1,j, vis);
    //     c += helper(grid, i-1,j, vis);
    //     c += helper(grid, i,j-1, vis);
    //     return vis[i][j] = c+1;
    // }
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
    //     int mx = 0;
    //     for(int i=0; i<grid.size(); i++) {
    //         for(int j=0; j<grid[i].size(); j++) {
    //             mx = max(mx, helper(grid, i, j, vis));
    //         }
    //     }

    //     return mx;
    // }
};