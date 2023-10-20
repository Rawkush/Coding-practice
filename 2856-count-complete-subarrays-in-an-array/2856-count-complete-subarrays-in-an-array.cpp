class Solution {
public:

  int helper(vector<int>& nums, int k){
    int count = 0;
    int left=0;
    int right =0;
    unordered_map<int, int> mp;

    while(right<nums.size()){
      mp[nums[right]]++;
      while(mp.size()>k){
        mp[nums[left]]--;
        if(mp[nums[left]]<=0) mp.erase(nums[left]);
        left++;
      }
      count += right-left+1;
      right++;
    }

    return count;
  }

  int countCompleteSubarrays(vector<int>& nums) {
   unordered_map<int, int> mp;
   
   // get total distinct numbers
   for(int i=0; i<nums.size(); i++){
    mp[nums[i]]++;
   }
    int k = mp.size();
    return helper(nums ,k) - helper(nums, k-1);
  }
};