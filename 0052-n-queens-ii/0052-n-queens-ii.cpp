class Solution {
public:

    bool isSafe(vector<string>& grid, int row, int col) {
        // check if same col have queen
        for (int i = row; i >= 0; i--) {
            if (grid[i][col] == 'Q')
                return false;
        }
        // should not have any queen on left upper digonal
        int i = row;
        int j = col;
        while (i >= 0 && j >= 0) {
            if (grid[i--][j--] == 'Q')
                return false;
        }
        // should not have any queen on right upper digonal
        i = row;
        j = col;
        while (i >= 0 && j < grid.size()) {
            if (grid[i--][j++] == 'Q')
                return false;
        }

        return true;
    }

    int helper(vector<string>&grid, int row){
        int n= grid.size();
        if(row>= n){
            return 1;
        }
        int sum =0;
        for(int i =0; i<n; i++){
            if(isSafe(grid, row, i)){
                grid[row][i]='Q';
                sum+=helper(grid, row+1);
                grid[row][i]='.';
            }
        }
        return sum;
    }

    int totalNQueens(int n) {
        string r="";
        for(int i =0; i<n; i++) r+=".";
        vector<string> grid(n, r);
        return helper(grid, 0);
    }
};
