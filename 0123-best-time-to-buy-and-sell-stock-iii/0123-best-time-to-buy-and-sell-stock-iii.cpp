class Solution {
public:
    int helper(vector<int>&  prices, int idx, int canBuy, int k, vector<vector<vector<int>>>&dp){
        if(idx>=prices.size() ||  k<=0)return 0;
        if(dp[idx][canBuy][k]!=-1) return dp[idx][canBuy][k];
        int profit = 0;
        if(canBuy){
            int p1 = -prices[idx] + helper(prices, idx+1, 0, k, dp); // if boiught
            int p2 =  helper(prices, idx+1, 1, k, dp); // did not buy
            profit = max(p1, p2);
        }else{
            int p1 = prices[idx] +  helper(prices, idx+1, 1, k-1, dp);
            int p2 = helper(prices, idx+1, 0, k, dp);
            profit = max(p1,p2);
        }
        return dp[idx][canBuy][k]= profit;
    }

    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, -1)));
        return helper(prices, 0, 1, 2, dp );    
    }
};