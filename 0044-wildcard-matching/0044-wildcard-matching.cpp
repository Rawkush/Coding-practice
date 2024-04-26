class Solution {
public:

    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        int n = s.size();
        int m  = p.size();
        dp[0][0]= true; 
        // if string is aa, patern is empty it will ways be false bcz pattern is not equal to str
        for(int i=1; i<=n; i++) dp[i][0] = false; // not needed as default is false, but added for clarity

        // if string is empty we need to see if pattern can match empty string
        for(int j=1; j<=m; j++) {
           if(p[j-1]=='*')  dp[0][j] = dp[0][j-1];
           else dp[0][j]= false;
        }

        for(int i =1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                if(p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                if(p[j-1]=='*'){
                    dp[i][j]= dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }

    // bool helper(string &s, string &p, int i, int j, vector<vector<int>>&dp){ // i, j is size
    //     if(i==0 && j==0) return true;
    //     if(j==0) return false;
    //     if(dp[i][j]!=-1) return dp[i][j]==1; // 1 means true 0 for false
    //     if(i==0) {
    //         if(p[j-1]=='*') return dp[i][j]=helper(s, p, i, j-1, dp);
    //         else return dp[i][j]=false;
    //     }
    //     if(s[i-1]==p[j-1]) return dp[i][j]=helper(s,p, i-1, j-1, dp);
    //     if(p[j-1]=='?') return dp[i][j]=helper(s, p, i-1, j-1, dp);
    //     if(p[j-1]=='*') return dp[i][j]=helper(s, p, i-1, j, dp) || helper(s, p, i, j-1, dp);
    //     return dp[i][j]=false;
    // }

    // bool isMatch(string s, string p) {
    //     vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
    //     return helper(s,p, s.size(), p.size(), dp);
    // }
};