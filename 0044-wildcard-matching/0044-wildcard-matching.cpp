class Solution {
public:


    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        vector<int> prev(m+1, false);
        vector<int> curr(m+1, false);

        prev[0] = true;
        for(int j=1; j<=m; j++){
            prev[j] = p[j-1]=='*' && prev[j-1];
        }
        for(int i =1; i<=n; i++){
            curr[0] = false;
            for(int j=1; j<=m; j++){
                if(p[j-1]=='*') curr[j] = curr[j-1] || prev[j];
                else 
                if(p[j-1]=='?' || s[i-1]==p[j-1]) curr[j] = prev[j-1];
                else curr[j]= false; 
            }
            prev= curr;
        }
        return prev[m];
    }


    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    //     dp[0][0] = true;

    //     for(int i=1; i<=m; i++){
    //         dp[0][i] = p[i-1]=='*' && dp[0][i-1];
    //     }
    //     for(int i =1; i<=n; i++){
    //         for(int j=1; j<=m; j++){
    //             if(p[j-1]=='*') dp[i][j] = dp[i][j-1] || dp[i-1][j];
    //             else 
    //             if(p[j-1]=='?' || s[i-1]==p[j-1]) dp[i][j] = dp[i-1][j-1]; 
    //         }
    //     }
    //     return dp[n][m];
    // }
 

    // bool helper(string &s, string &p, int i, int j, vector<vector<int>>&dp){
    //     if(i<=0 && j<= 0) return true;
    //     if(j<=0 ) return false;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(i<=0) return dp[i][j]=p[j-1]=='*' && helper(s, p, i, j-1, dp);
    //     if(p[j-1]=='*') return dp[i][j] = helper(s, p, i-1, j, dp) || helper(s, p, i , j-1, dp);
    //     if(p[j-1]=='?' || s[i-1]==p[j-1]) return dp[i][j] = helper(s, p, i-1, j-1, dp);
    //     return dp[i][j] =false;
    // }
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));


    //     return helper(s, p , s.size(), p.size(), dp);
    // }

    /**
    * Brute force
    */
    // bool helper(string &s, string &p, int i, int j){
    //     if(i<=0 && j<= 0) return true;
    //     if(j<=0 ) return false;
    //     if(i<=0) return p[j-1]=='*' && helper(s, p, i, j-1);
    //     if(p[j-1]=='*') return helper(s, p, i-1, j) || helper(s, p, i , j-1);
    //     if(p[j-1]=='?' || s[i-1]==p[j-1]) return helper(s, p, i-1, j-1);
    //     return false;
    // }
    // bool isMatch(string s, string p) {
    //     return helper(s, p , s.size(), p.size());
    // }
};