class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        for(int i=1; i<n; i++){ // p
            for(int j=i; j<=n; j++){ //c
                int t = prices[j-1]-prices[i-1] ;
                t =  t>=0 ? t: 0;
                t=t+prev[j-1];
                int nt = curr[j-1];
                curr[j]=max(t, nt); 
            } 
            prev= curr;
        }
        // not dp[n][n] bcz, you cannot sell if bought at last
        return prev[n];
    }


    /**
    * iterative
    */
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    //     for(int i=1; i<=n; i++){ // p
    //         for(int j=i; j<=n; j++){ //c
    //             int t = prices[j-1]-prices[i-1] ;
    //             t =  t>=0 ? t: 0;
    //             t=t+dp[i-1][j-1];
    //             int nt = dp[i][j-1];
    //             dp[i][j]=max(t, nt); 
    //         } 
    //     }
    //     // not dp[n][n] bcz, you cannot sell if bought at last
    //     return dp[n-1][n];
    // }


    /**
    * Memoization
    */
    // int helper(vector<int>& prices, int p,  int c, vector<vector<int>>&dp){
    //     if(p > c) return 0;
    //     if(c>=prices.size()) return 0;
    //     if(dp[p][c]!=-1) return dp[p][c];
    //     // sell today
    //     int t = prices[c] - prices[p] + helper(prices, c+1, c+1, dp);
    //     // do not selll today
    //     int nt = helper(prices, p, c+1, dp);
    //     return dp[p][c]= max(t, nt);
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //     return helper(prices, 0, 0, dp);
    // }


    /**
    * Brute force
    */
    // int helper(vector<int>& prices, int p,  int c){
    //     if(c>=prices.size()) return 0;
    //     // sell today:
    //     int t = prices[c] - prices[p] + helper(prices, c+1, c+1);
    //     // do not selll today
    //     int nt = helper(prices, p, c+1);
    //     return max(t, nt);
    // }

    // int maxProfit(vector<int>& prices) {
    //     return helper(prices, 0, 0);
    // }
};