bool canPartitionHelper(vector<int> & nums, int target, int sum, int index, vector<vector<int>>&mem){
  if(sum==target)return true;
  if(sum>target) return false;
  if(index>= nums.size()) return false;
  if(mem[index][sum]!=-1) return mem[index][sum]==1;
  bool include = canPartitionHelper(nums, target, sum + nums[index], index+1, mem);
  bool notInclude = canPartitionHelper(nums, target, sum, index+1, mem);
  mem[index][sum] = (include || notInclude)? 1:0;
  return include || notInclude;
}
bool canPartition(vector<int> &nums){
  if(nums.size()==0) return false;
  long sum=0;
  for(int i=0; i<nums.size(); i++){
    sum = sum + nums[i];
  }
  if(sum%2!=0) return false;
  vector<vector<int>> mem(nums.size()+1, vector<int>((sum/2+1),-1));

  return canPartitionHelper(nums, sum/2, 0, 0, mem);
}