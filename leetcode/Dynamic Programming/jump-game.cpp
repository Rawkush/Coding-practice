int maxResultHelper( vector<int>& nums, int k, int current,  vector<int>&mem){
  if(current>= nums.size()) return INT_MIN;
  if(current==nums.size()-1) {
    return nums[current];
  }
  if(mem[current]!=INT_MIN) return mem[current];
  int result = INT_MIN;
  for(int i=current+1; i<= min((int)nums.size()-1, current+k); i++){
    result = max(result, maxResultHelper(nums,k, i , mem));
  }
  mem[current] = result +  nums[current];
  return mem[current];
}

int maxResult(vector<int> &nums, int k){
  vector<int> mem(nums.size(), INT_MIN);
  return maxResultHelper(nums,k,0,mem);
}

//tabularization => still TLE
int maxResult(vector<int> &nums, int k ){
  vector<int> mem(nums.size(), INT_MIN);
  mem[nums.size()-1]=nums[nums.size()-1];
  for(int i=nums.size()-2, i>=0; i--){
    int maxVal= INT_MIN;
    for(int j=min(nums.size()-1, i+k); i--){
      maxVal=max(nums[i]+mem[j],maxVal);
    }
    mem[i] = maxVal;
  }
  return mem[0];
}