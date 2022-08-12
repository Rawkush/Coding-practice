  char intInChar[] = {"0123456789"};

class Solution {
public:

bool isSafe(vector<vector<char>> & board, int row, int col, int num){
  // check in same row
  for(int j = 0; j < board.size(); j++){
    if(board[row][j]==intInChar[num]) return false;
  }
  // check in same column
  for(int j = 0; j < board.size(); j++){
    if(board[j][col]==intInChar[num]) return false;
  }
  // check in cell of 3x3
  int rowFactor = row-(row%3);
  int colFactor = col-(col%3);
  for(int i=rowFactor; i<rowFactor+3; i++){
    for(int j=colFactor; j<colFactor+3; j++){
      if(board[i][j]==intInChar[num]) return false;
    }
  }
  return true;
}

bool findEmptyLocation(vector<vector<char>> &board, int &row, int &col){
  for(int i=0; i<board.size(); i++){
    for(int j=0; j<board[i].size(); j++){
      if(board[i][j]=='.'){
        row=i;
        col=j;
        return true;
      }
    }
  }
  return false;
}

bool solveSudokuHelper(vector<vector<char>> & board){
 int row, col;
  if(!findEmptyLocation(board, row ,col))  return true;

  for(int i = 1; i <=9; i++){
    if(isSafe(board, row, col, i)){
      board[row][col] = intInChar[i];
      if(solveSudokuHelper(board)) return true;
      board[row][col] = '.';
    }
  }
  return false;
}

void solveSudoku(vector<vector<char>>& board) {
  solveSudokuHelper(board);
}
};