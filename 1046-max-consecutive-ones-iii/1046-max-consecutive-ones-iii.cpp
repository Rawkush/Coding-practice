class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int count = k;
    int l=0;
    int r=0;
    int mx=0;
    while(r<nums.size()){
     if(nums[r]==0){    
        // if(count>0){ // allow fliping of this 0
        //   count--;
        // }
        // else{
        //   // remove all elements till we find 0
        //   while(nums[l]!=0){
        //     l++;
        //   }
        //   // remove this first 0, so our current 0 element i.e nums[r] can be flipped
        //   l++;
        // }

        count--;
        while(count<0){
          if(nums[l]==0)count++;
          l++;
        }
      }
      mx = max(r-l+1, mx);
      r++;
    }
    return mx;
  }
};