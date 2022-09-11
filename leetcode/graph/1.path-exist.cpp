
  bool helper(unordered_map<int, vector<int>>&graph, int source, int destination, vector<bool>&isVisited){
    if(source<0) return false;
    if(source >= isVisited.size()) return false;
    if(source == destination) return true;
    if(isVisited[source]) return false;
    vector<int> vertices = graph[source];
    isVisited[source] = true;
    bool result =false;
    for(auto vtx: vertices){
      result = result || helper(graph, vtx, destination, isVisited);
    }
    return result;
  }

  bool validPath(int n, vector<vector<int>> &edges, int source, int destination){
    unordered_map<int, vector<int>> graph;
    for(auto e: edges){
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    vector<bool> isVisited(n, false);
    return helper(graph, source, destination, isVisited);
  }