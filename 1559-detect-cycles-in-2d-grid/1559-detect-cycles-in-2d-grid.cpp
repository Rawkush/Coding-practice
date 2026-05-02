class DisjointSet {
    unordered_map<int,int> parent, size;
    public:
    int findP(int n) {
        if(parent.find(n)==parent.end()){
            size[n]=1;
            return parent[n] = n;
        }
        if(parent[n]==n) return n;
        return parent[n] = findP(parent[n]);
    }

    void unionBySize(int u, int v) {
        int p1 = findP(u);
        int p2 = findP(v);
        if(p1==p2) return;
        if(size[p2]>size[p1]) {
            swap(p1,p2);
        }
        size[p1]+=size[p2];
        parent[p2] =p1;
    }
};

class Solution {
public:

    //Union find

    int get1DIdx(int i, int j, int n) {
      return n*i + j;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        // eavery items is an node, and its path right and bottom are edges from this node to next node.
        DisjointSet ds;
        int n=grid[0].size();
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<n; j++){
                //assuming 2d array to one D and getting the index
                int u = get1DIdx(i, j, n); // edge 1
                //check if we can go right
                if(j+1 < grid[0].size() && grid[i][j] == grid[i][j+1]) {
                    //checkl if edge is already there, if yes there is a cycle
                    int v = get1DIdx(i, j+1, n); // 2nd edge
                    int p1 = ds.findP(u);
                    int p2 = ds.findP(v);
                    if(p1==p2) return true;
                    ds.unionBySize(u, v);
                }
                //go bottom check the same 
                if(i+1 < grid.size() && grid[i][j] == grid[i+1][j]) {
                    //checkl if edge is already there, if yes there is a cycle
                    int v = get1DIdx(i+1, j, n); // 2nd edge
                    int p1 = ds.findP(u);
                    int p2 = ds.findP(v);
                    if(p1==p2) return true;
                    ds.unionBySize(u, v);
                }
            }
        }
        return false;
    }



    // //DFS
    // bool helper(vector<vector<char>>& grid, vector<vector<int>> &isVisited, int row, int col, int pr, int pc) {
    //     if(row<0 || col<0 || row >= grid.size() || col>= grid[0].size() ) return false;
    //     // if(isVisited[row][col]==1) return true;
    //     isVisited[row][col]=1;
    //     //up
    //     if(row-1 >= 0 && grid[row-1][col] == grid[row][col]) {
    //         if(isVisited[row-1][col]==0) {
    //             if(helper(grid, isVisited, row-1, col, row, col )) return true;
    //         } else {
    //             //already visited, and not previous item
    //             if(!(row-1==pr && col==pc)) return true;
    //         }
    //     }
    //     //down
    //     if(row+1 < grid.size() && grid[row+1][col] == grid[row][col]) {
    //         if(isVisited[row+1][col]==0) {
    //             if(helper(grid, isVisited, row+1, col, row, col )) return true;
    //         } else {
    //             //already visited, and not previous item
    //             if(!(row+1==pr && col==pc)) return true;
    //         }
    //     }   
    //     //left 
    //     if(col-1 >= 0 && grid[row][col-1] == grid[row][col]) {
    //         if(isVisited[row][col-1]==0) {
    //             if(helper(grid, isVisited, row, col-1, row, col )) return true;
    //         } else {
    //             //already visited, and not previous item
    //             if(!(row==pr && col-1==pc)) return true;
    //         }
    //     } 
    //     //right
    //     if(col+1 < grid[0].size() && grid[row][col+1] == grid[row][col]) {
    //         if(isVisited[row][col+1]==0) {
    //             if(helper(grid, isVisited, row, col+1, row, col )) return true;
    //         } else {
    //             //already visited, and not previous item
    //             if(!(row==pr && col+1==pc)) return true;
    //         }
    //     }
    //     return false;
    // }

    // bool containsCycle(vector<vector<char>>& grid) {
    //     vector<vector<int>> isVisited(grid.size(), vector<int>(grid[0].size(), 0));
    //     for(int i =0; i<grid.size();i++) {
    //         for(int j=0; j<grid[i].size(); j++) {
    //             if(isVisited[i][j]==1) continue;
    //             if(helper(grid, isVisited, i, j, -1, -1)) return true;
    //         }
    //     }
    //     return false;
    // }
};