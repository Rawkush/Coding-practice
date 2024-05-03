class Solution {
public:

/**
* space optimzation
*/
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minN = INT_MAX;
        int n= matrix.size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for(int i =0; i<matrix.size(); i++){
            curr[i]=matrix[n-1][i]; 
        }
        prev= curr;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int ld= INT_MAX;
                int d=INT_MAX;
                int rd = INT_MAX; 
                if(j>0) ld = prev[j-1]; 
                d = prev[j];
                if(j+1<n) rd = prev[j+1];
                curr[j] =  min(ld, min(d,rd)) + matrix[i][j];
            }
            prev= curr;
        }
        for(int i=0; i<n; i++){
            minN = min(minN, curr[i]);
        }
        return minN;
    }



/**
* Iterative
*/
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int minN = INT_MAX;
    //     int n= matrix.size();
    //     vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    //     for(int i =0; i<matrix.size(); i++){
    //         dp[n-1][i]=matrix[n-1][i]; 
    //     }
    //     for(int i=n-2; i>=0; i--){
    //         for(int j=0; j<n; j++){
    //             int ld= INT_MAX;
    //             int d=INT_MAX;
    //             int rd = INT_MAX; 
    //             if(j>0) ld = dp[i+1][j-1]; 
    //             d = dp[i+1][j];
    //             if(j+1<n) rd = dp[i+1][j+1];
    //             dp[i][j] =  min(ld, min(d,rd)) + matrix[i][j];
    //         }
    //     }
    //     for(int i=0; i<n; i++){
    //         minN = min(minN, dp[0][i]);
    //     }
    //     return minN;
    // }

/**
* Recursive
*/
    // int helper(vector<vector<int>>& grid, int row, int col, vector<vector<int>>&dp){
    //     int n = grid.size()-1;
    //     if(row<0 || row<0 || row>n || row>n) return INT_MAX;

    //     if(row==n){
    //         return grid[row][col];
    //     }
    //     if(dp[row][col]!=INT_MAX) return dp[row][col];
    //     int lb = INT_MAX;
    //     int b=INT_MAX;
    //     int rb= INT_MAX;
    //     if(col!=0) lb = helper(grid, row+1 , col-1, dp); //left bottom
    //     if(col!=n) rb = helper(grid, row+1, col+1, dp );
    //     b = helper(grid, row+1, col, dp);
    //     return  dp[row][col]=min(lb, min(rb, b)) + grid[row][col]; 
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int minN = INT_MAX;
    //     int n= matrix.size();
    //     vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    //     for(int i =0; i<matrix.size(); i++){
    //         minN = min(minN,helper(matrix, 0, i, dp));
    //     }
    //     return minN;
    // }
};