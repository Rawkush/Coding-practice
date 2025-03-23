class Solution {
public:
    int thirdMax(vector<int>& nums) {
      long long firstMax=LLONG_MIN;
      long long secondMax=LLONG_MIN;
      long long thirdMax=LLONG_MIN;
      for(auto x: nums){
        if(firstMax==x || secondMax==x || thirdMax==x) continue;

        if(firstMax<x){
          thirdMax = secondMax;
          secondMax= firstMax;
          firstMax=x;
        }else if(secondMax<x){
          thirdMax=secondMax;
          secondMax=x;
        }else if(thirdMax<x){thirdMax=x;}
      }
      if(thirdMax==LLONG_MIN) return firstMax;
      return thirdMax;
    }
};