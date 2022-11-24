#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Edge{
  public:
  int v1;
  int v2;
  int w;
  Edge(int v1, int v2, int w){
    this->v1 = v1;
    this->v2 = v2;
    this->w = w;
  }
};

static int cmp(Edge a, Edge b){
 return a.w<b.w;
}



int findMinVertex(vector<int> weights, vector<int> visited){

}


int spanningTree(int V, vector<vector<int>> adj[]){
  //a[i][0];
  //v1 => i
  // v2=> a[i][0][0]
  //weight=> a[i][0][1]
  vector<Edge> edgeList;
  for(int i = 0; i < V; i++){
    int v1 = i;
    //adj[i]=> list containing two integer=> v2, w
    for(int j = 0; j <adj[i].size(); j++){
      //adj[i][j]
      edgeList.push_back( Edge(i,adj[i][j][0], adj[i][j][1]));
    }
  }
  // sort(edgeList.begin(),edgeList.end(),cmp);
  // vector<int> parents(V);
  // vector<int> rank(V,0);
  vector<int> parents(V);
  vector<int> weights(V);
  vector<bool> visited(V);
  for(int i = 0; i < V; i++){
    parents[i]=i;
    weights[i]=INT_MAX;
    visited[i]=false;
  }

}