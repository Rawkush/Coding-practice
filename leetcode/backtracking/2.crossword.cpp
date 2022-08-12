#include<iostream>
#include<vector>
using namespace std;
bool crossHelper(vector<vector<char>>& board,
  string word, int row, int col,
  int wordIndex){
  if(row>=board.size() || col>=board[0].size() || row<0 || col<0 ){
    return wordIndex==word.size();
  }
  if(board[row][col]=='#' && wordIndex!=0) return wordIndex==word.size();

  if(board[row][col]!= ' ' && board[row][col] != word[wordIndex]) return false;

  int idx = wordIndex;
  char c = board[row][col];
  if(board[row][col]== ' ' || board[row][col] == word[wordIndex]){
    board[row][col]=word[idx];
    idx=idx+1;
  }
  bool res = crossHelper(board, word, row-1, col, idx)
              || crossHelper(board, word, row, col-1, idx)
              || crossHelper(board, word, row+1, col, idx)
              || crossHelper(board, word, row, col+1, idx)
              ;
  board[row][col]= c;
  return res;
}

bool placeWordInCrossword(vector<vector<char>>& board, string word) {
  // find all position from where the word can start,
  // check if we can add out word from that point
}

int main(){
  vector<vector<char>> board;
  string word="abc";
  {
  vector<char> v1;
  v1.push_back('#');
  v1.push_back(' ');
  v1.push_back('#');
  board.push_back(v1);
  }
  {
  vector<char> v1;
  v1.push_back(' ');
  v1.push_back(' ');
  v1.push_back('#');
  board.push_back(v1);
  }
    {
  vector<char> v1;
  v1.push_back('#');
  v1.push_back('c');
  v1.push_back(' ');
  board.push_back(v1);
  }
  // for(int i=0; i<3; i++){
  //   vector<char> v1;
  //   for(int j=0; j<3; j++){
  //     char c;
  //     cin>>c;
  //     v1.push_back(c);
  //   }
  //   board.push_back(v1);
  //   cout<< placeWordInCrossword(board, word);
  // }
  return 0;
}