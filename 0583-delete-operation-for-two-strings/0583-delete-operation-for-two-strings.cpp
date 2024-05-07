class Solution {
public:
    //space optimizatrion
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        for(int i=0; i<=n; i++)  curr[i]=i;
        prev = curr;        
        for(int i=1; i<=m; i++){
            curr[0]=i;
            for(int j=1; j<=n; j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                    curr[j] = min(prev[j],curr[j-1]) +1;
                }
            }
            prev= curr;
        }
        
        return curr[n];
    }

    // int minDistance(string word1, string word2) {
    //     int m = word1.size();
    //     int n = word2.size();
    //     vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    //     for(int i=0; i<=m; i++)  dp[i][0]=i;
    //     for(int i=0; i<=n; i++)  dp[0][i]=i;
        
    //     for(int i=1; i<=m; i++){
    //         for(int j=1; j<=n; j++){
    //             if(word1[i-1]==word2[j-1]){
    //                 dp[i][j] = dp[i-1][j-1];
    //             }else{
    //                 dp[i][j] = min(dp[i-1][j], dp[i][j-1]) +1;
    //             }
    //         }
    //     }
        
    //     return dp[m][n];
    // }


    // int helper(string w1, string w2, int i, int j, vector<vector<int>>&dp){
    //     if(i>=w1.size() && j>=w2.size()) return 0;
    //     if(i>=w1.size()) return w2.size()-j;
    //     if(j>=w2.size()) return w1.size()-i;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(w1[i]==w2[j]) return dp[i][j]=helper(w1, w2, i+1, j+1, dp);
    //     // delete from w1
    //     int l = helper(w1,w2,i+1, j, dp);
    //     //delete from w2
    //     int r = helper(w1,w2, i, j+1, dp);
    //     return dp[i][j]=min(l,r) +1;
    // }
    // int minDistance(string word1, string word2) {
    //     vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
    //     return helper(word1, word2, 0, 0, dp);
    // }
};