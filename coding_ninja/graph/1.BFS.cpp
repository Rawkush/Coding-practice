#include <iostream>
using namespace std;
#include <unordered_map>
#include <queue>

void printBFS(vector<vector<int>>& matrix){
  queue<int> q;
  vector<bool> isVisited(matrix.size(), false);
  int numVertices = matrix.size();
  for(int vertex = 0; vertex < numVertices; vertex++ ){
    if(isVisited[vertex]) continue;
    q.push(vertex); // 0 indicates which vertex
    while(!q.empty()){
      int currentVertex = q.front();
      q.pop();
      if(isVisited[currentVertex]) continue;
      isVisited[currentVertex] = true;
      cout<<currentVertex<<" ";
      for(int destination=0; destination<numVertices; destination++){
        if(isVisited[destination]) continue;
        int isEdge = matrix[currentVertex][destination];
        if(isEdge==0) continue;
        isVisited[destination] = true;
        q.push(destination);
        // cout<<destination<<" ";
      }
    }
  }
}

int main() {

    // take input
    int v,e;
    cin>>v>>e;
    vector<vector<int>> matrix(v, vector<int>(v,0));

    for(int i=0; i<e;i++){
        int a, b;
        cin>>a>>b;
        matrix[a][b]=1;
        matrix[b][a]=1;
    }

    //print BFS
    printBFS(matrix);
}