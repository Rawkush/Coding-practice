class Solution {
public:
    /**
     * a graph is bipartite if we color nodes with 2 color, and each node colr
     * should not be equal to its neighbour
     */

    /**
        BFS
    */
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n = graph.size();
    //     vector<int> vis(n, -1);
    //     queue<int> q;
    //     for (int i = 0; i < n; i++) {
    //         int color = 0; // 0, 1, two colors
    //         if (vis[i] == -1) {
    //             q.push(i);
    //             vis[i] = color;
    //             color = 1;
    //         }
    //         while (!q.empty()) {
    //             int lvl = q.size();
    //             for (int j = 0; j < lvl; j++) {
    //                 int cnode = q.front();
    //                 q.pop();
    //                 vector<int> adnodes = graph[cnode];
    //                 for (auto x : adnodes) {
    //                     if (vis[x] == -1) {
    //                         q.push(x);
    //                         vis[x] = color;
    //                     } else if (vis[x] != color) {
    //                         return false;
    //                     }
    //                 }
    //             }
    //             color = (color + 1) % 2;

    //         }
    //     }
    //     return true;
    // }


    /**
    *     DFS
    */
 
    bool helper(vector<vector<int>>&graph, vector<int>&vis, int node, int color){
        if(vis[node]!=-1) return vis[node]==color;
        vis[node] = color;
        vector<int> adnodes= graph[node];
        for(auto x:adnodes){
            if(!helper(graph, vis, x, !color)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(vis[i]!=-1) continue;
            bool res = helper(graph, vis, i, 0);
            if(!res) return false;
        }
        return true;
    }
};