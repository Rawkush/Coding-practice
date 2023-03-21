class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int count = 1;
    for(int i=0; i< arr.size(); i++){
      if(arr[i]<=k) k++;
    }
    return k;
  }
};