
struct comparator{
  bool operator()(int a, int b){
    return a > b;
  }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, comparator> pq;
      for(int i=0; i<k; i++){
        pq.push(nums[i]);
      }  
      int size=nums.size();
      for(int i =k;i<size;i++){
        if(nums[i]>pq.top()){
          pq.pop();
          pq.push(nums[i]);
        }
      }
   
      return pq.top();
    }
};