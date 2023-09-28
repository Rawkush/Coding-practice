#define log(x) cout<<#x<<" "<<x;
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int trow = grid.size()-1;
    int tcol = trow; //target col, target row
    // vector<vector<int>> grid(grid.size(), vector<int>(grid.size(), 0));
    if(grid[0][0]==1) return -1;
    grid[0][0] =1;
    queue<pair<int,int>> q;//row, col
    q.push({0,0});
    int count = 0;
    while(!q.empty()){
      //level size
      int size = q.size();
      count+=1; //level of the BFS
  // cout<< "level"<<count<<" ";
      for(int i=0; i<size; i++){
        pair<int, int> cor = q.front();
        q.pop();
        int row = cor.first;
        int col = cor.second;
        // cout<<row<<" "<<col<<" : ";
        if(col==tcol && row ==trow){
          return count;
        }

        //eight possible moves

        //upper left diagonal
        if(col!=0 && row!=0 && !grid[row-1][col-1]){
          q.push({row-1, col-1});
          grid[row-1][col-1]=1;
        }

        // up
        if(row!=0 && !grid[row-1][col]){
          q.push({row-1, col});
          grid[row-1][col]=1;
        }

        //right up diagonal
        if(row!=0 && col!=tcol && !grid[row-1][col+1] ){
          q.push({row-1, col+1});
          grid[row-1][col+1]=1;
        }

        //right
        if(col!=tcol && !grid[row][col+1]){
          q.push({row, col+1});
          grid[row][col+1]=1;
        }

        //left
        if(col!=0 && !grid[row][col-1]){
          q.push({row, col-1});
          grid[row][col-1];
        }
        //lef grid bottom diagonal
        if(row!=trow && col!=0 && !grid[row+1][col-1] ){
          q.push({row+1, col-1});
          grid[row+1][col-1]=1;
        }

        //bottom

        if(row!=trow && !grid[row+1][col]){
          q.push({row+1, col});
          grid[row+1][col]=1;
        }

        //right bottom diagnonal
        if(row!=trow && col!=tcol && !grid[row+1][col+1]){
          q.push({row+1, col+1});
          grid[row+1][col+1]=1;
        }
      }
// cout<<endl;
    }
    return -1;
  }
};