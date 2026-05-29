#include<algorithm>
class Solution {
public:
    int minElement(vector<int>& nums) {
       int mn = INT_MAX;
       for(auto x:nums) {
            string s = to_string(x);
            int sum =0;
            for(auto y:s) {
                sum+=y-'0';
            }
            mn = min(mn, sum);
       } 
       return mn;
    }
};