class Solution {
public:

  int helper(vector<int>& nums, int goal) {
    int r=0, l=0, count =0;
    int sum=0;
    if(goal<0) return 0;

    while(r<nums.size()){
      sum += nums[r];
      while(sum>goal){
        sum -= nums[l];
        l++;
      }
      count += r-l+1;
      r++;
    }    
    return count;
  }

  int numSubarraysWithSum(vector<int>& nums, int goal) {
    return helper(nums, goal) - helper(nums, goal-1);
  }
};