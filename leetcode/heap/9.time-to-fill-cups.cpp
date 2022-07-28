class Solution {
public:
    int fillCups(vector<int>& amount) {
      int sum = 0;
      int mx = max(amount[0], max(amount[1], amount[2]));
      for(int i=0; i< amount.size(); i++) sum += amount[i];
      return max(mx, (int)ceil((double)sum/2));
    }
};