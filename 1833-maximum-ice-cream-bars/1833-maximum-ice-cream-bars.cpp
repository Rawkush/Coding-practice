class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> sorted(1e5+1, 0);
        for(auto c: costs) {
            sorted[c]++;
        }
        int mx =0;
        for(int i=0; i<=1e5; i++) {
            if(coins<=0) break;
            if(i > coins) break;
            if(sorted[i]>0) {
                int n = coins/i;
                // n is max number he can buy;
                int candies = min(n, sorted[i]);
                mx+=candies;
                coins -= candies*i;
            }
        }
        return mx;
    }
};