class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    vector<int> result;
    int midIndex=-1;
    //Findind first occurence
    while(left<=right){
      int mid = left + (right-left)/2;
      if(nums[mid]==target){
        midIndex = mid;
        right = midIndex-1;
      }else
      if(nums[mid]<target){
        left = mid+1;
      }else{
        right = mid-1;
      }
    }
    
    result.push_back(midIndex);
    //finding last occurenc
    left=0;
    right=nums.size()-1;
    while(left<=right){
      int mid = left + (right-left)/2;
      if(nums[mid]==target){
        midIndex = mid;
        left = midIndex+1;
      }else
      if(nums[mid]<target){
        left = mid+1;
      }else{
        right = mid-1;
      }
    }
    result.push_back(midIndex);
    return result;
  }
};