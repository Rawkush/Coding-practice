class Solution {
public:

  int helper(vector<int>&nums, int k ){
   int l=0, r=0, count =0;
   int odd = 0, even=0;
   while(r<nums.size()){
      if(nums[r]%2==1){
        odd++;
      }

      while(odd>k){
        if(nums[l]%2==1) odd--;
        l++;
      }

     count += r-l+1;
     r++;
   }
   return count;   
  }
  int numberOfSubarrays(vector<int>& nums, int k) {
    return helper(nums, k) -  helper(nums, k-1);
  }
};