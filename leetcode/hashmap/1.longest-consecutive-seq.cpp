#include <unordered_map>
class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_map<int, bool> map;
    for(int x: nums) map[x] = true;

    int count =0;
    int mx =0;
    for(int i : nums){
      if(!map[i]) continue;
      int in=i;
      while(map[in]){
        count++;
        map[in++] = false;
      }
      in = i-1;
      while(map[in]){
        count++;
        map[in--] = false;
      }
      mx=max(count, mx);
      count=0;
    }
    return mx;
  }
};
