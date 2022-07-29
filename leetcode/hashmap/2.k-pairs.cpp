#include<unordered_map>
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for(int x: nums){
      if(map.count(x) > 0) map[x]++;
      else map[x] =1;
    }
    int count = 0;
    unordered_map<int, int>::iterator it = map.begin();
    while(it != map.end()){
      if(k==0){
        if(it->second>1) count++;
      }else
      if(map.count(it->first + k) > 0){
        count++;
      }
      it++;
    }
    return count;
  }
};