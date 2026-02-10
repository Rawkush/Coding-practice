class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int mx =0;
        // num , freequency
        int i=0, j=0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int total = 0;
            unordered_map<int, int> even, odd;
            for(int j=i; j<n; j++) {
                if(nums[j]%2 == 0) {
                    //even
                    even[nums[j]]++;
                }else {
                    //odd
                    odd[nums[j]]++;
                }
                total++;
                if(even.size() == odd.size()) mx = max(mx, total);
            }
        }
        return mx;
    }
};