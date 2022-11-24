class Solution {
public:
bool helper(vector<vector<char>>& board, string& word, int index, int row, int col, vector<vector<bool>>&isVisited){
  if(index>= word.size()) return true;
  if(row<0 || row>=board.size() || col<0 || col>=board[0].size()) return false;
  if(isVisited[row][col]) return false;
  if(board[row][col]!= word[index]) return false;
  isVisited[row][col] = true;
  bool res = helper(board, word, index+1, row, col-1, isVisited )||
        helper(board, word, index+1, row, col+1, isVisited ) ||
        helper(board, word, index+1, row-1, col, isVisited ) ||
        helper(board, word, index+1, row+1, col, isVisited );
  isVisited[row][col]= false;
  return res;
}

bool exist(vector<vector<char>> &board, string word){
  bool result = false;
  vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
  for(int i = 0; i < board.size(); i++){
    for(int j = 0; j < board[0].size(); j++){
      if(board[i][j] == word[0]){
        result = result || helper(board, word, 0, i, j, isVisited);
      }
    }
  }
  return result;
}
};