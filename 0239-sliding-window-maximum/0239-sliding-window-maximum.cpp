class Solution {
public:
// can be solved using PQ, with size k
  void print(queue<int> q){
      while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
      }
      cout<<endl;
  }
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> res;
    for(int i=0;i<k; i++){ 
      while(!q.empty() && q.back()> q.front()) q.pop_front();
      while(!q.empty() && q.back() < nums[i] ) q.pop_back();
      q.push_back(nums[i]);
    }
    res.push_back(q.front());
    for(int i=0, j=k; j<nums.size(); i++, j++){
      if(q.front()==nums[i]) q.pop_front();
      // while(!q.empty() && q.back()> q.front()) q.pop_front();
      while(!q.empty() && q.back() < nums[j] ) q.pop_back();
      q.push_back(nums[j]);
      res.push_back(q.front());
    }

    return res;
  }
};