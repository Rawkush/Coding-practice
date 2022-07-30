#include<unordered_map>
class Solution{
public:
  // Complete this function
  // Function to check whether there is a subarray present with 0-sum or not.
  bool subArrayExists(int arr[], int n){
    // Your code here
    unordered_map<int, int> map;
    int sum = 0;
    for(int i = 0; i < n; i++){
      sum += arr[i];
      if(sum==0) return true;
      if(map.count(sum) > 0){
        return true;
      }else
        map[sum]=i;
    }
    return false;
  }
};