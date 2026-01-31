class Solution {
public:
    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>>&dp) {
        if(i >= s1.size() && j >= s2.size()) return 0;
        if(dp[i][j]>0) return dp[i][j];
        int sum1 = 0, sum2 = 0, sum3 = 0;
        if(i<s1.size()){
            sum1 = lcs(s1, s2, i+1, j, dp);
        }
        if(j<s2.size()) {
            sum2 = lcs(s1, s2, i, j+1, dp);
        }
        if(s1[i]==s2[j]) sum3 = (int)s1[i] + lcs(s1,s2, i+1, j+1, dp);
        return dp[i][j] = max({sum1, sum2, sum3});
    }


    int minimumDeleteSum(string s1, string s2) {
        int totalSum = 0;
        for(auto x: s1) {
            totalSum += (int)x;
        }
        for(auto x:s2){
            totalSum+=(int)x;
        }
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        int lcsSum =  lcs(s1, s2, 0, 0, dp);
        return totalSum - 2*lcsSum;
    }
};