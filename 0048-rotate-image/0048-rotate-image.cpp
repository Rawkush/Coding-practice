class Solution {
public:
    void transpose(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
            for(int j=i; j<grid.size(); j++) {
                swap(grid[i][j], grid[j][i]);
            }
        }
    }

    void print(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid.size(); j++) {
                cout<<grid[i][j] << " ";
            }
            cout<<endl;
        }
    }

    void rotate(vector<vector<int>>& grid) {
        transpose(grid);
        print(grid);
        for(auto &x: grid) {
            reverse(x.begin(), x.end());
        }
    }
};