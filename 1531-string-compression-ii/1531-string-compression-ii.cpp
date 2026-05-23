class Solution {
public:
    int freequencyCompress(int i) {
        if(i<=1) return i;
        // if(i<10) return 2;
        // if(i<99) return 3;
        // if(i<999) return 4;
        // return 5;
        return ("a" + to_string(i)).size();
    }
    int helper(string &s, int i, int k, char p, int f, unordered_map<int,unordered_map<int,unordered_map<int, unordered_map<int,int>>>> &dp) {
        if(k<0) return INT_MAX;
        if(k==0 && i==s.size()) {
            return freequencyCompress(f);
        }
        if(i>=s.size()) return INT_MAX;
        if(dp[i][k][p-'a'].count(f)>0) return dp[i][k][p-'a'][f];
        /** If we delete current element */
        long notTake = helper(s,i+1,k-1, p, f, dp);
        // if we do not delete the current element
        long take = 0;
        /** Current element is  equal to previous */
        if(s[i] == p) {
            take += helper(s, i+1, k, p, f+1, dp);
        } else {
            // if not equeal then
            take += freequencyCompress(f);
            take += helper(s, i+1, k, s[i], 1, dp);
        }

        return dp[i][k][p-'a'][f]=min(notTake, take);
    }

    int getLengthOfOptimalCompression(string s, int k) {
        unordered_map<int,unordered_map<int,unordered_map<int, unordered_map<int,int>>>> dp;
        return helper(s, 0, k, s[0], 0, dp);    
    }
};