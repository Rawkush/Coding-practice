class Solution {
public:
/** space optimizated **/
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        int n = text1.size(); 
        int m = text2.size();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1]==text2[j-1]) curr[j] = 1+prev[j-1];
                else {
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }   
            prev= curr;
        }
        return curr[m];
    }   



    /**
    * thgis can be simplifed if we shift the abse case, that is we start from empty string instead
    * of string idx 0
    */
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
    //     int n = text1.size(); 
    //     int m = text2.size();
    //     dp[0][0] = text1[0]==text2[0]? 1: 0;
    //     //base cases
    //     for(int i=1; i<text1.size(); i++){
    //         dp[i][0]=text1[i]==text2[0]? 1: dp[i-1][0];
    //     }
    //     //base cases
    //     for(int i=1; i<text2.size(); i++){
    //         dp[0][i] = text1[0]==text2[i]? 1: dp[0][i-1];
    //     }

    //     for(int i=1; i<text1.size(); i++){
    //         for(int j=1; j<text2.size(); j++){
    //             if(text1[i]==text2[j]) dp[i][j] = 1+dp[i-1][j-1];
    //             else {
    //                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }   
    //     }
    //     return dp[n-1][m-1];
    // }    


    // int helper(string  &text1, string &text2, int i, int j, vector<vector<int>>&dp){
    //     if(i>= text1.size() || j>= text2.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i]==text2[j]) return dp[i][j] = 1 + helper(text1, text2, i+1, j+1, dp);
    //     else{
    //         int l1 = helper(text1, text2, i+1, j, dp);
    //         int l2 = helper(text1, text2, i, j+1, dp);
    //         return dp[i][j]=max(l1,l2);
    //     }
    //     return 0;
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    //     return  helper(text1, text2, 0, 0, dp);
    // }
};