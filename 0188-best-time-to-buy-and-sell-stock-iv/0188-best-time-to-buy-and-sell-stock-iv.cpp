class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> curr(3, vector<int>(k+1, 0));
        vector<vector<int>> ahead(3, vector<int>(k+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                for(int kt=1; kt<=k; kt++){
                    int p =0;
                    if(j){
                        int p1 = -prices[i] + ahead[0][kt];
                        int p2 = ahead[1][kt];
                        p = max(p1, p2);
                    }else{
                        int p1 = prices[i] + ahead[1][kt-1];
                        int p2 = ahead[0][kt];
                        p = max(p1,p2);
                    }
                    curr[j][kt] =p;
                }
            }
            ahead = curr;
        }
        return curr[1][k];    
    }
};