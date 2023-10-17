class Solution {
public:
//
  long long continuousSubarrays(vector<int>& nums) {
    long long count =  0;
    int st = 0;
    int i=0;
    deque<int> maxq;
    deque<int> minq;
    while(i<nums.size()){
      while(!maxq.empty() && maxq.back()<nums[i]) maxq.pop_back();
      while(!minq.empty() && minq.back() > nums[i]) minq.pop_back();
      maxq.push_back(nums[i]);
      minq.push_back(nums[i]);
      while(!maxq.empty() && !minq.empty() && abs(maxq.front()-minq.front())>2){
        if(nums[st]==maxq.front()) maxq.pop_front();
        if(nums[st]==minq.front()) minq.pop_front();
        st++;
      }
      count += i-st +1;
      i++;
    }
    return count;
  }
};