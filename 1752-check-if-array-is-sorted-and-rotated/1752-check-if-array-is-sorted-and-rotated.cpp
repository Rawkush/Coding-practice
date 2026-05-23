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
            if(nums[i] > nums[i+1]) return false; // if not sorted then false
        }
        
        //since second part is sorted therefore at index ri there was roation, now confirm if left array is completely bigger than 2nd, since both are sorted we can use first index of first and last idx of second
        if(nums[0] < nums[n-1]) return false;
        return true;
    }
};