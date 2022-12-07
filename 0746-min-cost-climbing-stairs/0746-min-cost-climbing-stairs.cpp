class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size()+1, 0);
        memo[0]=0;
        memo[1]=0;
        for(int i=2; i<=cost.size(); i++){
            int cost1 = memo[i-1] + cost[i-1];
            int cost2 = memo[i-2] +cost[i-2];
            memo[i] = min(cost1,cost2);
        }   
        return memo[cost.size()];
    }
    // int minCostHelper(vector<int>&cost, int index, vector<int>&memo){
    //     if(index<=1) return 0;
    //     if(memo[index]!=0) return memo[index];
    //     int cost1 = minCostHelper(cost, index-1, memo) +cost[index-1];
    //     int cost2= minCostHelper(cost, index-2, memo) + cost[index-2];   
    //     memo[index] = min(cost1, cost2);
    //     return memo[index]; 
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     vector<int> memo(cost.size()+1, 0);
    //    return minCostHelper(cost, cost.size(), memo);
    // }
};