#include<iostream>
#include<vector>
using namespace std;

int checkeryPickOnwayBack(vector<vector<int>> &grid, int row, int col, int result){
  if(row ==0 && col ==0){
    return result + grid[row][col];
  }
  if( row<0 || col<0 ) return 0;
  if(grid[row][col]==-1) return 0;
  int tmp = grid[row][col];
  grid[row][col] = 0;
  int left = checkeryPickOnwayBack(grid, row, col-1, result + tmp);
  int up = checkeryPickOnwayBack(grid, row-1, col, result + tmp);
  grid[row][col] = tmp;
  return max(left,up);

}

int cherryPickupHelper(vector<vector<int>> &grid, int row, int col, int result, int mem[][51]){
  if(row>=grid.size() || col>=grid.size()) return 0;
  if(row == grid.size()-1 && col == grid.size()-1){
    int cherryPicked = checkeryPickOnwayBack(grid, row, col, 0);
    return result + cherryPicked;
  }
  if(grid[row][col]==-1) return 0;
  if(mem[row][col]!=-1) return mem[row][col];
  int tmp = grid[row][col];
  grid[row][col]=0;
  int right = cherryPickupHelper(grid, row, col+1, result + tmp, mem);
  int bottom = cherryPickupHelper(grid, row+1, col, result + tmp, mem);
  grid[row][col] = tmp;
  int ans = max( right, bottom);
  mem[row][col]=ans;
  return mem[row][col];
}

int cherryPickup(vector<vector<int>> &grid){
  int mem[51][51];
  memset(mem, -1, 51*51*sizeof(int));
  return cherryPickupHelper(grid, 0, 0, 0, mem);
}

int main(){
  vector<vector<int>> grid;
  {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(-1);
    grid.push_back(v);
  }
  {
    vector<int> v;
    v.push_back(1);
    v.push_back(-1);
    v.push_back(1);
    grid.push_back(v);
  }
  {
    vector<int> v;
    v.push_back(-1);
    v.push_back(1);
    v.push_back(1);
    grid.push_back(v);
  }
  cout<< cherryPickup(grid);
  return 0;
}