class Solution {
public:
    /**
    * we use bits to tell which item to pick and which not to pick
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int s = (1<<n); //number of subsets
        vector<vector<int>> res;
        for(int i=0; i<s; i++) {
            vector<int> sub;
            // in current bit, find all non zero items to pick
            for(int j=0; j<n; j++) {
                if((i&(1<<j))!=0) sub.push_back(nums[j]);
            }
            res.push_back(sub);
        }
        return res;
    }
};