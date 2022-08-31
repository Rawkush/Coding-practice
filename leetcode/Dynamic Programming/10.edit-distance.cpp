int minDistanceHelper(string word1, string word2, vector<vector<int>> &mem){
  if(word1.size()==0 || word2.size()==0){
    return max(word1.size(), word2.size());
  }
  int m= word1.size();
  int n= word2.size();
  if(mem[m][n]!=INT_MAX) return mem[m][n];
  int ans=INT_MAX;
  if(word1[0]==word2[0]){
    ans= minDistanceHelper(word1.substr(1), word2.substr(1),mem);
  }
  else{
    int x = minDistanceHelper(word1.substr(1),word2,mem);
    int y = minDistanceHelper(word1, word2.substr(1),mem);
    int z = minDistanceHelper(word1.substr(1), word2.substr(1),mem);
    ans= min(x, min(y, z)) +1;
  }
  mem[m][n]=ans;
  return mem[m][n];
}
int minDistance(string word1, string word2){
  vector<vector<int>> mem(word1.size()+1, vector<int>(word2.size()+1,INT_MAX));
  return minDistanceHelper(word1, word2, mem);
}

///Tabularization


int minDistance(string word1, string word2){
  vector<vector<int>> mem(word1.size()+1, vector<int>(word2.size()+1,INT_MAX));
  int m = word1.size();
  int n= word2.size();
  mem[0][0]=0;

  // fill first row
  for(int i=1; i<=n; i++){
    mem[0][i]=i;
  }
  // fill first column
  for(int i=1; i<=m; i++){
    mem[i][0]=i;
  }

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(word1[i-1]==word2[j-1]){
        mem[i][j]= mem[i-1][j-1];
      }else{
        int a = mem[i-1][j];
        int b= mem[i-1][j-1];
        int c=mem[i][j-1];
        mem[i][j]=min(a,min(b,c))+1;
      }
    }
  }
  return mem[m][n];
}
