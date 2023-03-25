class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int si =0;
    int li = nums.size()-1;
    while(si<li){
      //find first odd number
      while(nums[si]%2==0 && si<li) si++;
      
      //find first even number from behind
      while(nums[li]%2==1 && li>si) li--;
      
      if(si>li) break;
      //here we found both odd and even
      swap(nums[si], nums[li]);
      
    }
    return nums;
  }
};