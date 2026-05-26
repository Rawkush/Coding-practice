class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int mx= INT_MIN; 
       int s = 0;
       for(auto x: nums) {
            s+=x;
            mx = max(mx, s);
            if(s<=0) s = 0;
       }
       return mx;
    }
};