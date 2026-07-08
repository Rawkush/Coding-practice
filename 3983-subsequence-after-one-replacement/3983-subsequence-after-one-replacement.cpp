class Solution {
public:
    bool helper(string &s, string &t, int i, int j, bool replaced,  unordered_map<int, unordered_map<int, unordered_map<int,int>>> &dp) {
        if(i>=s.size()) return true;
        if(j>=t.size()) return false; //out of bound
        if(s.size()-i > t.size()-j) return false; // pre return
        bool ans = false;
        if(dp.count(i) > 0 && dp[i].count(j) > 0 && dp[i][j].count(replaced)>0)return dp[i][j][replaced]==1;
        if(s[i]==t[j]) {
            if(i==s.size()-1) return true; // if this is hte end
            ans = helper(s, t, i+1, j+1, replaced, dp);
        } else {
            ans = ans || helper(s, t, i, j+1, replaced, dp);
            if(!replaced) ans = ans || helper(s, t, i+1, j+1, true, dp);
        }
        return dp[i][j][replaced]= ans? 1: 0;
    }
    bool canMakeSubsequence(string s, string t) {
        unordered_map<int, unordered_map<int, unordered_map<int,int>>> dp;
        return helper(s, t, 0, 0, false, dp);
    }
};