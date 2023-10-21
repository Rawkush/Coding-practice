class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int count = k;
    int l=0;
    int r=0;
    int mx=0;
    while(r<nums.size()){
     if(nums[r]==0){    
        if(count>0){ // allow fliping of this 0
          count--;
        }
        else{
          while(nums[l]!=0){
            l++;
          }
          l++;
        }
      }
      // cout<<l<<" "<<r<<" "<<count<<endl;
      mx = max(r-l+1, mx);
      r++;
    }
    return mx;
  }
};