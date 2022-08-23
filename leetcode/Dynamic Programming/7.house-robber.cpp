int robHelper(vector<int>& nums, int index, int mem[]){
  if(index>= nums.size()) return 0;
  if(mem[index]!=-1) return mem[index];
  int first =  nums[index] + robHelper(nums, index+2, mem);
  int second = robHelper(nums, index+1, mem);
  mem[index] =  max(first, second);
  return mem[index];
}

int rob(vector<int> &nums){
  int mem[101];
  memset(mem, -1 , 101*sizeof(int));
  return robHelper(nums, 0, mem);
}

// DP
int rob(vector<int> &nums){
  int mem[101];
  mem[0]= nums[0];
  if(nums.size() == 1) return nums[0];
  mem[1]= max(mem[0], nums[1]);
  for(int i=2; i<nums.size() ; i++){
    mem[i] = max(nums[i] + mem[i-2], mem[i-1]);
  }
  return mem[nums.size()-1];
} 