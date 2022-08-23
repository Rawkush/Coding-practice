int robHelper( vector<int>& nums, int index, bool flag, int mem[][2]){
  if(index>= nums.size()) return 0;
  if(index==nums.size()-1 && flag) return 0;
  if(mem[index][flag]!=-1) return mem[index][flag];
  int first = 0;
  int second = 0;
  if(index == 0){
    first = nums[index] + robHelper(nums, index+2, true, mem);
  }else{
    first= nums[index] + robHelper(nums, index+2, flag, mem);
  }
  second =  robHelper(nums, index+1, flag, mem);
  mem[index][flag]= max(first, second);
  return mem[index][flag];
}

int rob(vector<int> &nums){
  if(nums.size()==1) return nums[0];
  int mem[101][2];
  memset(mem, -1, 101*2*sizeof(int));
  int res= robHelper(nums, 0, false, mem);
  return res;
}

// DP solution


int rob(vector<int> &nums){
  if(nums.size()==1) return nums[0];
  int mem[101][2];
  mem[0][0]=0;
  mem[0][1]= nums[0];
  mem[1][0] = nums[1];
  mem[1][1] = max(nums[1], mem[0][1]);
  for(int i=2; i< nums.size(); i++){
    // mem[i] = max(nums[i] + mem[i-2], mem[i-1]);
    mem[i][0] = max(nums[i] + mem[i-2][0], mem[i-1][0]);
    if(i==nums.size()-1)
      mem[i][1]=mem[i-1][1];
    else
    mem[i][1]= max(nums[i] + mem[i-2][1], mem[i-1][1]);
  }
  return max(mem[nums.size()-1][0], mem[nums.size()-1][1]);
}
