class Solution {
public:
        int helper(string &s, string &r, int i, int j, vector<vector<int>>&dp){
        if(i>=s.size() || j>= r.size()) return 0;\
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==r[j]) return dp[i][j] = 1+ helper(s, r, i+1, j+1, dp);
        int l1= helper(s, r, i+1, j, dp);
        int l2 = helper(s,r, i, j+1, dp);
        return dp[i][j]=max(l1, l2);
    }

    int longestSubsequence(string s, string s2){
        vector<vector<int>>dp(s.size(), vector<int>(s2.size(), -1));
        return helper(s, s2, 0, 0, dp);
    }

    /**
    * comparing string with its reverse for common subsequence will give palindome
    * subsequence
    */

    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return longestSubsequence(s, r);
    }
    /**
    * subtracting longest palindrom from total length will give us item which needs
    * to be added
    */
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};