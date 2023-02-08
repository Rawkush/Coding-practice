class Solution {
public:
    int findMin(vector<int>& nums) {
      int left = 0;
      int right =nums.size()-1;
      int n = nums.size();
      while(left<right){
        int mid = left + (right -left)/2;
        int prev = (mid+n-1)%n;
        int next = (mid+1)%n;
        if(nums[mid]<nums[prev] && nums[mid]<nums[next]){
          return nums[mid];
        }
        else if(nums[mid]<nums[right]){
          right =mid-1;
        }else{
          left= mid+1;
        }
      }
      return nums[left];
    }
};