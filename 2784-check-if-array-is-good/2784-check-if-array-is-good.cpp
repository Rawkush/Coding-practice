class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mx=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            mx= max(mx, nums[i]);
        }
        if(mx != nums.size()-1) return false;
        vector<int>mp(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
            if(nums[i]!=mx && mp[nums[i]]>1) return false;
            if(mp[nums[i]] > 2) return false;
        }
        return true;
    }
};