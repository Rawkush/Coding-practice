class Solution {
public:

    int helper(vector<int>&nums, int curr, int prev, vector<vector<int>>&dp){
        if(curr<0) return 0;
        // take curr, we can only take curr if prev < curr
        if(dp[curr][prev]!=-1) return dp[curr][prev];
        int l1=0;
        if(prev==nums.size() || nums[prev]>nums[curr]){
            l1 = 1 + helper(nums, curr-1, curr, dp);
        }
        // do not take curr element in subs
        int l2 = helper(nums, curr-1, prev, dp);

        return dp[curr][prev] = max(l1, l2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+2, -1));
        return helper(nums, nums.size()-1, nums.size(), dp);
    }
};