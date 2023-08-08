class Solution {
public:
//-ve marking
  int findDuplicate(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
      int index = abs(nums[i]);
      int itemAtIdx = nums[index];
      if(itemAtIdx<0) return index;
      nums[index] = -nums[index];
    }
    return 0;
  }
};