bool canPartitionHelper(vector<int> & nums, int target, int sum, int index){
  if(sum==target)return true;
  if(index>= nums.size()) return false;
  int include = canPartitionHelper(nums, target, sum + nums[index], index+1);
  int notInclude = canPartitionHelper(nums, target, sum, index+1);
  return include || notInclude;
}
bool canPartition(vector<int> &nums){
  if(nums.size()==0) return false;
  long sum=0;
  for(int i=0; i<nums.size(); i++){
    sum = sum + nums[i];
  }
  if(sum%2!=0) return false;
  return canPartitionHelper(nums, sum/2, 0, 0);
}