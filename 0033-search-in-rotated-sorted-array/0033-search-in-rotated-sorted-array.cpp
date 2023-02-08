class Solution {
public:
  int findPivot(vector<int>&nums){
    int left = 0;
    int right =nums.size()-1;
    int n = nums.size();
    while(left<right){
      int mid = left + (right -left)/2;
      int prev = (mid+n-1)%n;
      int next = (mid+1)%n;
      if(nums[mid]<nums[prev] && nums[mid]<nums[next]){
        return mid;
      }
      else if(nums[mid]<nums[right]){
        right =mid-1;
      }else{
        left= mid+1;
      }
    }
    return left;
  }

  int binarySearch(vector<int> &nums, int left, int right, int &target){
    while(left<right){
      int mid = left+(right-left)/2;
      if(nums[mid]==target) return mid;
      if(target>nums[mid]){
        left=mid+1;
      }
      else{
        right = mid-1;
      }
    }
    if(nums[left]==target) return left;
    return -1;
  } 

  int search(vector<int>& nums, int target) {
    int pivot = findPivot(nums);
    cout<<"pivot"<<pivot<<endl;
    //now we have two arrays, 0-pivot, and pivot-end
    //either do BS on both or, just check which one array to pick
    // based on where traget range lies
    //for simplicity i am calling BS on both sides
    int leftAns = binarySearch(nums, 0, pivot, target);
    int rightAns = binarySearch(nums, pivot, nums.size()-1, target);
    cout<<"left"<<leftAns<<endl;
    cout<<"right"<<rightAns<<endl;
    if(leftAns!=-1) return leftAns;
    if(rightAns!=-1) return rightAns;
    return -1; 
  }
};