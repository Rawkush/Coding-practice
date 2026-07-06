class Solution {
public:
    int helper(string &text1, string&text2, int i, int j, vector<vector<int>>&dp) {
        if(i>=text1.size() || j>=text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //pick current item
        int lcs = 0;
        if(text1[i]==text2[j]) return dp[i][j] = helper(text1, text2, i+1, j+1, dp) +1;
        lcs = max(lcs , helper(text1, text2, i, j+1, dp));
        lcs = max(lcs , helper(text1, text2, i+1, j, dp));
        return dp[i][j]=lcs;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, 0, 0, dp);
    }
};