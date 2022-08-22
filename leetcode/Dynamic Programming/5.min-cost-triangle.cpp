


int minimumTotalHelper(vector<vector<int>> & triangle, int row, int col, vector<vector<int*>> &mem){
  if(row>=triangle.size() || col>=triangle[row].size()) return INT_MAX;
  if(row==triangle.size()-1){
    return triangle[row][col];
  }
  if(mem[row][col]!=NULL) return mem[row][col];
  int minResult = new int(0);
  minResult=triangle[row][col] + min(minimumTotalHelper(triangle, row+1,col), minimumTotalHelper(triangle, row+1, col+1));
  triangle[row][col] = minResult;
  return minResult;
}

int minimumTotal(vector<vector<int>>& triangle) {
  vector<vector<int*>>mem(201,vector<int*>(201, NULL));
 return minimumTotalHelper(triangle, 0,0, mem);
}
