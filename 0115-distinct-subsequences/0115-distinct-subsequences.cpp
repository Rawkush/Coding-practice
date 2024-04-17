class Solution {
public:
    



    int helper(string s, string t, int idx1,  int idx2, vector<vector<int>>& dp){
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(idx1==0 && idx2==0) return s[idx1]==t[idx2]? 1: 0;
        int sum =0;
        if(s[idx1]==t[idx2]){
            sum+=helper(s, t, idx1-1, idx2-1, dp); // take the item
        }
        sum += helper(s, t, idx1-1, idx2, dp); // do not take curr item
        return dp[idx1][idx2]=sum;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return helper(s, t, s.size()-1, t.size()-1, dp);
    }


    // int helper(string s, string t, int idx1,  string sub){
    //     if(sub==t) return 1;
    //     if(idx1<0) return 0;
    //     //take curr
    //     int l = helper(s, t, idx1-1, s[idx1]+ sub);
    //     int r = helper(s, t, idx1-1, sub);
    //     return l+r;
    // }
    // int numDistinct(string s, string t) {
    //     return helper(s, t, s.size()-1, "");
    // }
};