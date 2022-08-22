//Brute Force
int pathHelper(int m, int n, int row, int col){
  if(row==m-1 && col==n-1) return 1;
  if(row>=m || col>=n) return 0;

  int right = pathHelper(m,n,row,col+1);
  int left = pathHelper(m,n,row+1, col);
  return right + left;
}
int uniquePaths(int m, int n){
  return pathHelper(m,n, 0 ,0);
}

//Memo
int pathHelper(int m, int n, int row, int col, int mem[][101]){
  if(row==m-1 && col==n-1) return 1;
  if(row>=m || col>=n) return 0;

  if(mem[row][col]!=-1) return mem[row][col];
  int right = pathHelper(m,n,row,col+1, mem);
  int left = pathHelper(m,n,row+1, col, mem);
  mem[row][col] = right + left;
  return mem[row][col];
}

int uniquePaths(int m, int n){
  int mem[101][101];
  memset(mem, -1, 101*101*sizeof(int));
  return pathHelper(m,n, 0 ,0, mem);
}

// Dynamic Programming
int uniquePaths(int row, int col){
  int mem[101][101];
  memset(mem, 0, 101*101*sizeof(int));
  mem[row-1][col-1]=1;
  // fill last row
  for(int i=col-2; i>=0; i--){
    mem[row-1][i] = mem[row-1][i+1];
  }
  // fill lasts col
  for(int i=row-2; i>=0; i--){
    mem[i][col-1] = mem[i+1][col-1];
  }

  for(int i=row-2; i>=0; i--){
    for(int j=col-2; j>=0; j--){
      mem[i][j] = mem[i+1][j] + mem[i][j+1];
    }
  }

  return mem[row-1][col-1];
}
