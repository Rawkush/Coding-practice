class Solution {
public:
    bool check(vector<int>& nums) {
        int c =0;
        int n = nums.size();
        int ri =-1; // rirst sorted array min
        for(int i=0; i<n-1; i++) {
            if(nums[i]>nums[i+1]) {
                ri = i;
                break;
            }
        }
        if(ri == -1) return true; // sorted array
        for(int i=ri+1; i<n-1; i++) {
            if(nums[i] > nums[i+1]) return false;
            if(nums[ri] < nums[i]) return false;
        }
        
        if(nums[ri] < nums[n-1]) return false; // last element should ne less than ri
        // if coming here it means above array is also sorted
        // now just need to see if first min is should also be bigger than last
        if(nums[0] < nums[n-1]) return false;
        return true;
    }
};