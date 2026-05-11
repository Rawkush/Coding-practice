class Solution {
public:
    int helper(vector<int>& nums, int target, int idx, vector<int>& dp){
        if(idx==nums.size()-1) return 0;
        if(dp[idx]!=INT_MIN) return dp[idx];
        int jumps = -1;
        for(int i=idx+1; i<nums.size(); i++) {
            if(((nums[i]-nums[idx])>=-target) && ((nums[i]-nums[idx])<=target)) {
                int j = helper(nums, target, i, dp);
                if(j>=0) {
                    jumps = max(jumps,j+1);
                }
            }
        }
        return dp[idx]=jumps;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), INT_MIN);
        return helper(nums, target, 0, dp);
    }
};