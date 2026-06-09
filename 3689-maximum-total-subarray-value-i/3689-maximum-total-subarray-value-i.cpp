class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx = INT_MIN;
        int mn = INT_MAX; 
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>mx) mx = nums[i];
            if(nums[i]<mn) mn = nums[i];
        }
        return (long long)k*(mx-mn);
    }
};