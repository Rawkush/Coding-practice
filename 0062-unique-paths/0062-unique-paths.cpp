class Solution {
public:


/**
* Space optimization
*/

    int uniquePaths(int m, int n) {
        vector<int>prev(n, 0);
        vector<int>curr(n, 0);

        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    curr[j]=1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if(i-1>=0) up = prev[j];
                if(j-1>=0) left =  curr[j-1]; 
                curr[j] = left+ up;
            }
            prev= curr;
        }
        return curr[n-1];
    }


/**
* Tablualtion
*/
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     dp[0][0] =1;

    //     for(int i =0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //             if(i==0 && j==0){
    //                 dp[i][j]=1;
    //                 continue;
    //             }
    //             int up = 0;
    //             int left = 0;
    //             if(i-1>=0) up = dp[i-1][j];
    //             if(j-1>=0) left =  dp[i][j-1]; 
    //             dp[i][j] = left+ up;
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }


    // int helper(int m, int n, vector<vector<int>>&dp){
    //     if(m==0 && n==0) return 1;
    //     if(m<0 || n<0) return 0;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int r = helper(m,n-1, dp);
    //     int d = helper(m-1, n, dp);
    //     return dp[m][n]=r+d;
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return helper(m-1,n-1, dp);
    // }
};