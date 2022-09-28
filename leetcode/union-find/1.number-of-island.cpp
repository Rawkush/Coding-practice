#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

void initParents(vector<int> &parents, vector<vector<char>>&grid){
  int m = grid.size();
  int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    parents[i*n+j]= i*n+j;
                }
            }
        }
}

int findParent(vector<int>& parents, int node){
  if(node==parents[node]){
    return node;
  }
  return parents[node] = findParent(parents, parents[node]);
}


void _union(vector<int>& parents, vector<int>&rank, int u, int v){
  int p1 = findParent(parents, u);
  int p2 = findParent(parents, v);
  if(p1 == p2) return;
  if(rank[p1]<rank[p2]){
    parents[p1]=p2;
  }else if(rank[p1]>rank[p2]){
    parents[p2]=p1;
  }else{
    parents[p1]=p2;
    rank[p1]++;
  }
}

int countIsland(vector<vector<char>>&grid, vector<int>& parents, vector<int>&rank){
  int m=grid.size();
  int n=grid[0].size();

  for(int i=0; i< m; i++){
    for(int j=0; j< n; j++){
      // row major order
      // grid[i][j] => parent[ i*m +j]
      if(grid[i][j]=='1'){
        //pick all four vertices and add them to the graph
        // add top edge
        if(i-1>=0 && grid[i-1][j]=='1'){
          _union(parents, rank, (i*n)+j, (i-1)*n +j);
        }
        //add bottom edge
        if(i+1<m && grid[i+1][j]=='1'){
          _union(parents,rank, ((i*n)+j), (i+1)*n +j );
        }
        //add left edge
        if(j-1>=0 && grid[i][j-1]=='1'){
          _union(parents, rank, (i*n)+j, (i*n)+(j-1));
        }
        //add right edge
        if(j+1<n && grid[i][j+1]=='1'){
          _union(parents, rank, (i*n)+j, (i*n)+(j+1));
        }
      }
    }
  }

  int count=0;

  for(int i=0;i<n*m;i++){
     if(parents[i]==i && parents[i]!=-1) count++;
  }

  return count;
}
  int numIslands(vector<vector<char>> &grid){
  vector<int> parents( grid.size()*grid[0].size(), -1);
  vector<int> rank(grid.size()*grid[0].size(), 0 );
  initParents(parents, grid);
  int c = countIsland(grid, parents, rank);
  //find distinct parents
  return c;
}
int main(){
  vector<vector<char>> grid;
  {
    vector<char> v1;
    v.push_back('1');
    v.push_back('0');
  }
  return 0;
}