class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size()-1;
    while(left<right){
     int mid = left+(right-left)/2;
      if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
        return nums[mid];
      }
      // if mid is even and left items does not have
      // the answer then the mid+1 should have the duplicate of mid
      // so the answer must be on the right of the data
      // else answer lies in left side
      if(mid%2==0){
        //since number is even, then if left part does not have the anser the mid+1
        // will be having the duplicate of the mid 
        // if mid+1 does not have the duplicate it means the data would be in left side of
        // the array
        if(nums[mid]==nums[mid+1]){
          left = mid+2;
        } else{
          right = mid-2;
        } 
      }else{
        if(nums[mid]==nums[mid-1]){
          left = mid+1;
        } else{
          right = mid-1;
        } 
      }
    }
    return nums[left];
  }
};