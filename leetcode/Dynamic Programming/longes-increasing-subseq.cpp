  int helper(vector<int> &nums, int index, int prev, vector<vector<int> > &mem){
    if(index>=nums.size()) return 0;
    // including current element
    if(mem[index][prev+1]!=-1) return mem[index][prev+1];
    int a = 0;
    if(prev==-1 || nums[index]>nums[prev])
      a= 1+ helper(nums, index+1, index, mem);
    int b = helper(nums, index+1, prev, mem);
    return mem[index][prev+1]= max(a,b);
  }
  int lengthOfLIS(vector<int> &nums){
    vector<vector<int>> mem(nums.size(), vector<int>(nums.size()+1,-1));
    return helper(nums, 0, -1, mem);
  }


