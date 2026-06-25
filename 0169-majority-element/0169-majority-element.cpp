class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int f = 0;
        int prev = nums[0];
        for(auto x: nums) {
            if(f==0) prev = x;
            if(prev == x) f++;
            else {
                f--;
            }
        }
        return prev;
    }
};