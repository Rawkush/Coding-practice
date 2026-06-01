class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        if(cost.size()==1) return cost[0];
        if(cost.size()==2) return cost[0] + cost[1];
        int totalCost =0;
        for(int i=cost.size()-1, j=1; i>=0; i--, j++) {
            if(j==3) {
                j=0;
                continue;
            } 
            totalCost+=cost[i];
        }
        return totalCost;
    }
};