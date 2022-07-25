//could also be done using heap

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int first=0, second=0;
      for(int x: nums){
        if(x>first){
          second=first;
          first=x;
        }else second=max(x, second);
      }
      return (first-1)*(second-1);
    }
};