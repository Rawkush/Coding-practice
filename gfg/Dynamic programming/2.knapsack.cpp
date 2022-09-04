int knapSackHelper(int W, int wt[], int val[], int n, int index, vector<vector<int>>&mem){
  if(index>=n) return 0;
  if(W==0) return 0;
  if(mem[W][index]!=-1) return mem[W][index];
  // include i
  int a = 0;
  if(W-wt[index]>=0)
  a= val[index] + knapSackHelper(W-wt[index], wt, val, n , index+1, mem);
  // do not include i
  int b = knapSackHelper(W, wt, val, n , index+1, mem);
  return mem[W][index]=max(a,b);
}
int knapSack(int W, int wt[], int val[], int n){
  vector<vector<int>> mem(W+1, vector<int> (n+1, -1) );
  return knapSackHelper(W, wt, val, n, 0, mem);
}

// tabularization
int knapSack(int W, int wt[], int val[], int n){
  vector<vector<int>> mem(W+1, vector<int> (n+1, -1) );
  mem[0][0]=0;

  // fill first row
  for(int i=0; i<=n; i++)
    mem[0][i]=0;

  // fill from col
  for(int i=1; i<=W; i++){
    if(wt[0]<=i)
      mem[i][0]= val[0];
    else mem[i][0]=0;
  }
  for(int i=1; i<=W; i++){
    for(int j=1; j<n; j++){
      int a = 0;
      if(i-wt[j]>=0){
        a = val[j] + mem[i-wt[j]][j-1];
      }
      int b=mem[i][j-1];
      mem[i][j]=max(a,b);
    }
  }
  return mem[W][n-1];
}
