 void helper(vector<vector<int>> &graph, vector<vector<int>> &allPaths, vector<int>& path, int vertices){
    if(vertices == graph.size()-1){
      path.push_back(vertices);
      allPaths.push_back(path);
      path.pop_back();
      return;
    }
    if(vertices >= graph.size()) return;
    if(vertices<0) return;
    path.push_back(vertices);
    for(auto vtx : graph[vertices]){
      helper(graph, allPaths, path, vtx);
    }
    path.pop_back();

  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph){
    vector<vector<int>> allPaths;
    vector<int> path;
    helper(graph, allPaths, path, 0);
    return allPaths;
  }