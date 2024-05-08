class Solution {
public:

    // space optimizatino
    int numDistinct(string s, string t) {
        // vector<vector<double>> dp(s.size()+1, vector<double>(t.size()+1, 0));
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1, 0);
        vector<double> curr(m+1, 0);
        // base case (if t="", for any string s we can make one "" empty string as subsequence)
        // for(int i=0; i<=n; i++) dp[i][0] =1;
        prev[0]=1;
        for(int i=1; i<=n; i++){
            curr[0]=1;
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=prev[j-1]+prev[j];
                }
                else curr[j]=prev[j];
            }
            prev= curr;
        }
        return curr[m];
    }    

    // iterative
//     int numDistinct(string s, string t) {
//         vector<vector<double>> dp(s.size()+1, vector<double>(t.size()+1, 0));
//         int n = s.size();
//         int m = t.size();
//         // base case (if t="", for any string s we can make one "" empty string as subsequence)
//         for(int i=0; i<=n; i++) dp[i][0] =1;

//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(s[i-1]==t[j-1]){
//                     dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
//                 }
//                 else dp[i][j]=dp[i-1][j];
//             }
//         }
//         return dp[n][m];
//     }


//MEMO


//     int helper(string s, string t, int idx1,  int idx2, vector<vector<int>>& dp){
//         if(idx2<0) return 1;
//         if(idx1<0) return 0;
//         if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
//         // if(idx1==0 && idx2==0) return s[idx1]==t[idx2]? 1: 0;
//         int sum =0;
//         if(s[idx1]==t[idx2]){
//             sum+=helper(s, t, idx1-1, idx2-1, dp); // take the item
//         }
//         sum += helper(s, t, idx1-1, idx2, dp); // do not take curr item
//         return dp[idx1][idx2]=sum;
//     }
//     int numDistinct(string s, string t) {
//         vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
//         return helper(s, t, s.size()-1, t.size()-1, dp);
//     }


//     int helper(string s, string t, int idx1,  string sub){
//         if(sub==t) return 1;
//         if(idx1<0) return 0;
//         //take curr
//         int l = helper(s, t, idx1-1, s[idx1]+ sub);
//         int r = helper(s, t, idx1-1, sub);
//         return l+r;
//     }
//     int numDistinct(string s, string t) {
//         return helper(s, t, s.size()-1, "");
//     }
};