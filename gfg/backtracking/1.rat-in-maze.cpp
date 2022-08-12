#include<iostream>
#include<vector>
using namespace std;


void findPathHelper(vector<vector<int>> &m, int n, string path,
 vector<string> &result, int row, int col){
  if(col>=n || row>=n || col<0 || row<0) return;
  if(m[row][col]==0) return;
  if(row==n-1 && col==n-1) {
    result.push_back(path);
    return;
  }
  int tmp = m[row][col];
  m[row][col] =0;
  // let's go to right;
  findPathHelper(m, n, path+'R', result, row, col+1);
  //left
  findPathHelper(m, n, path+'L', result, row, col-1);
  //up
  findPathHelper(m, n, path+'U', result, row-1, col);
  //down
  findPathHelper(m, n, path+'D', result, row+1, col);
  m[row][col]=tmp;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
  vector<string> result;
  string path="";
  findPathHelper(m, n, path, result, 0, 0);
  return result;
}

int main(){
  vector<vector<int>> result;
  findPath(result,0);
  return 0;
}