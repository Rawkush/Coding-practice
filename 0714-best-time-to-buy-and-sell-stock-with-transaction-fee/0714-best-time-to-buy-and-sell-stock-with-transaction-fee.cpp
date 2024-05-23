class Solution {
public:
    int f;


    //MEMO
    int helper(vector<int>&prices, int idx, int cb, vector<vector<int>>&dp){
        if(idx>=prices.size()) return 0;
        int p=0;
        if(dp[idx][cb]!=-1) return dp[idx][cb];
        if(cb){
            int p1 = -prices[idx] + helper(prices, idx+1, 0, dp);
            int p2 = helper(prices, idx+1, 1, dp);
            p = max(p1, p2);
        }else{
            int p1 = prices[idx] - f + helper(prices, idx+1, 1, dp);
            int p2 = helper(prices, idx+1, 0, dp);
            p = max(p1, p2);
        }
        return dp[idx][cb]=p;
    }

    int maxProfit(vector<int>& prices, int fee) {
        f=fee;
        int n =prices.size();
        vector<vector<int>>dp(n+1, vector<int>(3,-1));
        return helper(prices, 0, 1, dp);      
    }


    // int f;
    // int helper(vector<int>&prices, int idx, int cb){
    //     if(idx>=prices.size()) return 0;
    //     int p=0;
    //     if(cb){
    //         int p1 = -prices[idx] + helper(prices, idx+1, 0);
    //         int p2 = helper(prices, idx+1, 1);
    //         p = max(p1, p2);
    //     }else{
    //         int p1 = prices[idx] - f + helper(prices, idx+1, 1);
    //         int p2 = helper(prices, idx+1, 0);
    //         p = max(p1, p2);
    //     }
    //     return p;
    // }

    // int maxProfit(vector<int>& prices, int fee) {
    //     f=fee;
    //     return helper(prices, 0, 1);      
    // }
};