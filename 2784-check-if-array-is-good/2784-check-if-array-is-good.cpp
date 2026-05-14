class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size()==1) {
            return false;
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++) {
            if(i+1!=nums[i]) return false;
        }
        int n = nums.size()-1;
        // cout<<nums[n]<<" "<<cout<<nums[n-1];
        return nums[n]==nums[n-1] && nums[n] == n;
    }
};