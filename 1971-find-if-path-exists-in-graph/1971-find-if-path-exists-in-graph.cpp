class Solution {
public:
    
    void createGraph(vector<vector<int>> &edges, unordered_map<int, vector<int>> &graph) {
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        createGraph(edges, graph);
        queue<int> q;
        q.push(source);
        vector<bool> vis(n, false);
        vis[source] =true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == destination) return true;
            vector<int> neighbors = graph[node];
            for( auto x: neighbors) {
                if(vis[x]) continue;
                vis[x] = true;
                q.push(x);
            }
        }

        return false;
    }
};