class Solution {
public:
    //tabulation
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+2,  vector<int>(3,0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                int p =0;
                if(j){
                    int p1 = -prices[i] + dp[i+1][0];
                    int p2 = dp[i+1][1];
                    p = max(p1, p2);
                }else{
                    int p1 =  prices[i] +dp[i+2][1];
                    int p2 =  dp[i+1][0];
                    p = max(p1, p2);
                }
                dp[i][j] =p;
            }
        }
        return dp[0][1];
    }

    // MEMO
    //  int helper(vector<int>&prices, int idx, int canBuy, vector<vector<int>>&dp){
    //     if(idx>=prices.size()) return 0;
    //     if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
    //     int p =0;
    //     if(canBuy){ // can buy today
    //         int  p1 = -prices[idx] + helper(prices, idx+1, 0, dp);
    //         int p2 = helper(prices, idx+1, 1,  dp);
    //         p = max(p1, p2);
    //     }else{
    //         int p1 = prices[idx] +  helper(prices, idx+2, 1,dp);
    //         int p2 = helper(prices, idx+1, 0, dp);
    //         p = max(p1,p2);
    //     }
    //     return dp[idx][canBuy] =p;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n= prices.size();
    //     vector<vector<int>> dp(n+1,  vector<int>(3,-1));
    //     return helper(prices, 0, 1, dp);
    // }


    // int helper(vector<int>&prices, int idx, int canBuy){
    //     if(idx>=prices.size()) return 0;
    //     int p =0;
    //     if(canBuy){ // can buy today
    //         int  p1 = -prices[idx] + helper(prices, idx+1, 0);
    //         int p2 = helper(prices, idx+1, 1);
    //         p = max(p1, p2);
    //     }else{
    //         int p1 = prices[idx] +  helper(prices, idx+2, 1);
    //         int p2 = helper(prices, idx+1, 0);
    //         p = max(p1,p2);
    //     }
    //     return p;
    // }
    // int maxProfit(vector<int>& prices) {
    //     return helper(prices, 0, 1);
    // }




};