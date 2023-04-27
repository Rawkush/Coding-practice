class Solution {
public:
  void sortColors(vector<int>& nums) {
    int c1 = 0, c2=0, c3=0;
    for(int i=0; i< nums.size(); i++){
      if(nums[i]==0) c1++;
      if(nums[i]==1) c2++;
      if(nums[i]==2) c3++;
    }

    int idx=0;
    for(int i=0; i< c1; i++){
      nums[idx++]=0;
    }
    for(int i=0; i<c2; i++){
      nums[idx++] =1;
    }
    for(int i=0; i< c3; i++){
      nums[idx++]=2;
    }
  }
};