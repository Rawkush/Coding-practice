class Solution {
public:

// space optimization
  int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        int n = word1.size();
        int m = word2.size();
        // dp[0][0] = 0; // when both string are empty 0 opertion needed
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        // if word2 is empty
        // for(int i=1; i<=n; i++)dp[i][0]=i;

        //if word1 is e,pty()
        for(int i=1; i<=m; i++) curr[i]=i;

        prev= curr;
        for(int i=1; i<=n; i++){
            curr[0] = i;
            for(int j =1; j<=m; j++){
                int a = 1+ curr[j-1]; // character added 2 in w2
                int d = 1+ prev[j]; // char delete from w2 
                int r =1+ prev[j-1]; // replcaed
                int ans = min(a, min(d,r));
                if(word1[i-1]==word2[j-1]) ans= min(ans, prev[j-1]);
                curr[j]= ans;
            }
            prev= curr;
        }
        return curr[m]; 
    }



    // int minDistance(string word1, string word2) {
    //     vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, 0));
    //     int n = word1.size();
    //     int m = word2.size();
    //     dp[0][0] = 0; // when both string are empty 0 opertion needed
    //     // if word2 is empty
    //     for(int i=1; i<=n; i++)dp[i][0]=i;

    //     //if word1 is e,pty()
    //     for(int i=1; i<=m; i++) dp[0][i]=i;

    //     for(int i=1; i<=n; i++){
    //         for(int j =1; j<=m; j++){
    //             int a = 1+ dp[i][j-1]; // character added 2 in w2
    //             int d = 1+ dp[i-1][j]; // char delete from w2 
    //             int r =1+ dp[i-1][j-1]; // replcaed
    //             int ans = min(a, min(d,r));
    //             if(word1[i-1]==word2[j-1]) ans= min(ans, dp[i-1][j-1]);
    //             dp[i][j]= ans;
    //         }
    //     }
    //     return dp[n][m]; 
    // }


    // int helper(string &w1, string & w2, int i, int j, vector<vector<int>>&dp){
    //     if(i<0) return j +1;
    //     if(j<0) return i +1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int e = INT_MAX;
    //     if(w1[i]==w2[j]){
    //         e = helper(w1, w2,i-1, j-1, dp);
    //     }
    //     // add cha
    //     int a = 1+ helper(w1, w2, i, j-1, dp);
    //     // delete
    //     int d = 1+ helper(w1, w2, i-1, j, dp);
    //     //replcae
    //     int r = 1 +helper(w1, w2, i-1, j-1, dp);
    //     return   dp[i][j]=min(a, min(d,min(r, e)));
    // }

    // int minDistance(string word1, string word2) {
    //     vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, -1));
    //     return helper(word1, word2, word1.size()-1, word2.size()-1, dp);    
    // }
};