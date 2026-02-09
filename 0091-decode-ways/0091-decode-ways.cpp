class Solution {
public:
    int helper(string s, int idx, vector<int>&dp) {
        if(idx>=s.size()) return 1;
        if(s[idx] == '0' ) return 0;
        if(dp[idx]!=-1) return dp[idx];
        //if i use first character
        int c = helper(s, idx+1, dp);
        //if we use two characters together
        int d = 0;
        if(idx+1<s.size() && ((s[idx]-'0') * 10 + (s[idx+1]-'0')) <=26 ) {
            d = helper(s, idx+2, dp);
        }
        return dp[idx]=c+d;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return helper(s, 0, dp);
    }
};