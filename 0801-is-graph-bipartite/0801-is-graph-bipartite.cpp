class Solution {
public:
    /**
     * a graph is bipartite if we color nodes with 2 color, and each node colr
     * should not be equal to its neighbour
     */
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int color = 0; // 0, 1, two colors
            if (vis[i] == -1) {
                q.push(i);
                vis[i] = color;
                color = 1;
            }
            while (!q.empty()) {
                int lvl = q.size();
                for (int j = 0; j < lvl; j++) {
                    int cnode = q.front();
                    q.pop();
                    vector<int> adnodes = graph[cnode];
                    for (auto x : adnodes) {
                        if (vis[x] == -1) {
                            q.push(x);
                            vis[x] = color;
                        } else if (vis[x] != color) {
                            return false;
                        }
                    }
                }
                color = (color + 1) % 2;

            }
        }
        return true;
    }
};