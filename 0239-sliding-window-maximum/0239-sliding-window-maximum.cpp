
#include<queue>

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> pq;
    vector<int> result;
    for(int i=0; i<k;i++){
      pq.push(make_pair(nums[i],i));
    }
    result.push_back(pq.top().first);

    for(int i=k; i<nums.size(); i++){
      pq.push(make_pair(nums[i],i));
      int pos = pq.top().second;
      while(i-pos>=k){
        pq.pop();
        pos = pq.top().second;
      }
      result.push_back(pq.top().first);
    }
    return result;
  }
};