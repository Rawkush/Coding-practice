class Solution {
public:


  /**
    use array as hashmap
  */

  int helper(vector<int>& nums, int idx){
    if(idx>=nums.size()) return -1;
    int itm = nums[idx];
    int di = helper(nums, idx+1);
    if(di> 0) return di;
    if(nums[itm]==itm && itm!=idx) return itm;
    nums[itm] = itm;
    return -1;
  }

  int findDuplicate(vector<int>& nums) {
   return helper(nums, 0);
  }


  /**
  -ve marking
  */
  // int findDuplicate(vector<int>& nums) {
  //   for(int i=0; i<nums.size(); i++){
  //     int index = abs(nums[i]);
  //     int itemAtIdx = nums[index];
  //     if(itemAtIdx<0) return index;
  //     nums[index] = -nums[index];
  //   }
  //   return 0;
  // }
};