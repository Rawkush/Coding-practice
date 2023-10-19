class Solution {
public:

  // calculate all subset till valid
  int helper(vector<int>& nums, int k){
    unordered_map<int, int> mp; // value , count
    int i=0;
    int count =0;
    int st = 0;
    while(i<nums.size()){
      mp[nums[i]]++;
      while(mp.size()>k){
        mp[nums[st]]--;
        if(mp[nums[st]]==0) mp.erase(nums[st]);
        st++;
      }
      count += i-st+1;
      i++;
    }
    return count;
  }
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return (helper(nums, k)- helper(nums, k-1));
  }
};