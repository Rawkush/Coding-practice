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

void initParents(vector<int>& parents){
  for(int i = 0; i < parents.size(); i++){
    parents[i] = i;
  }
}

int findParent(int vertex, vector<int>& parents){
  if(vertex == parents[vertex]){
    return parents[vertex];
  }
  return parents[vertex] = findParent(parents[vertex], parents);
}

bool _union(int v1, int v2, vector<int>& parents, vector<int>&rank) {
  int p1 = findParent(v1, parents);
  int p2 = findParent(v2, parents);
  if(p1 == p2) return false;
  if(rank[p1]>rank[p2]){
    parents[p2] = p1;
  }else if(rank[p1]< rank[p2]){
    parents[p1] = p2;
  }else{
    parents[p1]=p2;
    rank[p1]++;
  }
  return true;
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
  sort(edgeList.begin(),edgeList.end(),cmp);
  vector<int> parents(V);
  vector<int> rank(V,0);

  initParents(parents);
  int weight = 0;

  for(int i = 0; i < edgeList.size(); i++){
    Edge edge = edgeList[i];
    if(_union(edge.v1, edge.v2, parents, rank)){
      weight+=edge.w;
    }
  }

  return weight;
}