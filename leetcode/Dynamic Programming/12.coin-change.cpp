
int coinChangeHelper(vector<int>& coins, int amount, vector<int>&mem){
  if(amount == 0) return 0;
  if(amount<0) return -1;
  int minCoins = INT_MAX;
  if(mem[amount]!=INT_MAX) return mem[amount];
  for(int i=0; i<coins.size(); i++){
    int ans= coinChangeHelper(coins, amount-coins[i], mem);
    if(ans==-1) continue;
    minCoins = min(minCoins, ans+1);
  }
  if(minCoins==INT_MAX){
    mem[amount]=-1;
  }else
  mem[amount] = minCoins;
  return mem[amount];
}
int coinChange(vector<int> &coins, int amount){
vector<int> mem(amount+1, INT_MAX);
 return coinChangeHelper(coins, amount,mem);
}

// tabularization
int coinChange(vector<int>& coins, int amount){
  vector<int> mem(amount+1, INT_MAX);
  mem[0]=0;

  for(int i=1; i<=amount; i++){
    int minCoins = INT_MAX;
    for(int j=0; j<coins.size(); j++){
      if(coins[j] <= i){
        if(mem[i-coins[j]]!=INT_MAX)
          minCoins =  min(minCoins,mem[i-coins[j]]+1);
      }
    }
    mem[i]= minCoins;
  }
  if(mem[amount]==INT_MAX) return -1;
  return mem[amount];
}