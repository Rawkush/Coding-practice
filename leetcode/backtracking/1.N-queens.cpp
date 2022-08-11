#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string>&board, int row, int col){

  //should not have any queen on same col
  for(int i=row; i>0; i--){
    if(board[i][col]=='Q') return false;
  }

  // should not have any queen on left upper digonal
  int i=row;
  int j=col;
  while(row>0 && col>0){
    if(board[i--][j--]=='Q') return false;
  }
  // should not have any queen on right upper digonal
  i=row;
  j=col;
  while(i>0 && j<board.size()){
    if(board[i--][j++]=='Q') return false;
  }

  return true;
}

void nQueensHelper(vector<string> &board, int row, vector<vector<string>> &solution) {
  if(row>=board.size()){
    solution.push_back(board);
    return;
  }
  for(int i = 0; i < board.size(); i++){
    if(isSafe(board, row, i)){
      board[row][i] = 'Q';
      nQueensHelper(board, row+1, solution);
      board[row][i] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<string> board;
  vector<vector<string>> solution;
  string tmp="";
  //creating empty board
  for(int i=0; i<n; i++){
    tmp+=".";
  }
  for(int i=0; i<n; i++){
    board.push_back(tmp);
  }
  nQueensHelper(board, 0, solution);
  return solution;
}

int main(){
  vector<vector<string>> sol = solveNQueens(4);
  for(auto v: sol){
    for(auto s: v) cout<<s<<" ";
    cout<<endl;
  }
  return 0;
}