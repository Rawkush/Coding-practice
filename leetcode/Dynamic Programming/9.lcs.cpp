int LCS(string &text1, string &text2, int index1, int index2, vector<vector<int>> &mem){
  if(index1>= text1.length()) return 0;
  if(index2>= text2.length()) return 0;
  int length =0;
  if(mem[index1][index2]!=-1) return mem[index1][index2];
  if(text1[index1]==text2[index2]){
    length = 1 + LCS(text1,text2, index1+1,index2+1, mem);
  }else{
    length = max( LCS(text1,text2,index1,index2+1, mem), LCS(text1,text2,index1+1,index2, mem) );
  }
  mem[index1][index2] =length;
  return mem[index1][index2];
}

int longestCommonSubsequence(string text1, string text2) {
  vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));
  return LCS(text1, text2, 0, 0, mem);
}

// tabularization
int longestCommonSubsequence( string text1, string text2){
  vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));

  if(text1[0]== text2[0]){
    mem[0][0]=1;
  }else mem[0][0]=0;

  // fill first col, i,.e col=0, row is changing
  for(int i=1; i<text1.size(); i++){
    if(text1[i]==text2[0]){
      mem[i][0]=1;
    }else mem[i][0]=mem[i-1][0];
  }


  // fill first row, i.ee row =0 and vary col
  for(int i=1; i<text2.size(); i++){
    if(text1[0]==text2[i]){
      mem[0][i]=1;
    }else mem[0][i]=mem[0][i-1];
  }

  for(int i=1; i<text1.size(); i++){
    for(int j = 1; j< text2.size(); j++){
      if(text1[i]==text2[j]){
        mem[i][j]= 1 +mem[i-1][j-1];
      }else mem[i][j]=max( mem[i-1][j],mem[i][j-1] );
    }
  }
  return mem[text1.size()-1][text2.size()-1];
}