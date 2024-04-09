class Solution {
public:
    int helper(string w1, string w2, int i, int j, vector<vector<int>>&dp){
        if(i>=w1.size() && j>=w2.size()) return 0;
        if(i>=w1.size()) return w2.size()-j;
        if(j>=w2.size()) return w1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]) return dp[i][j]=helper(w1, w2, i+1, j+1, dp);
        // delete from w1
        int l = helper(w1,w2,i+1, j, dp);
        //delete from w2
        int r = helper(w1,w2, i, j+1, dp);
        return dp[i][j]=min(l,r) +1;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        return helper(word1, word2, 0, 0, dp);
    }
};