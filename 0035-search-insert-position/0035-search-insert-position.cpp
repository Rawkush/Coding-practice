class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
      int mid = (left+right)/2;
      if(nums[mid]==target) return mid;
      if(nums[mid] > target){
        right = mid-1;
        continue;
      }
      if(nums[mid]<target){
        left=mid+1;
        continue;
      }
    }
    return left;
  }
};