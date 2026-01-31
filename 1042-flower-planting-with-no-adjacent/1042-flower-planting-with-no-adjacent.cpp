class Solution {
public:

    void createGraph(vector<vector<int>>&paths, unordered_map<int,vector<int>> &graph) {
        for(auto path: paths) {
            const int node = path[0];
            const int neighbour = path[1];
            graph[node-1].push_back(neighbour-1);
            graph[neighbour-1].push_back(node-1);
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> graph;
        createGraph(paths, graph);
        vector<int> res(n, -1);
        for(int i=0; i<n; i++) {
            vector<int> plants(4, -1);
            auto neighbors = graph[i];
            for(auto neighbour: neighbors) {
                if (res[neighbour]!=-1) {
                    plants[res[neighbour]-1] = 1;
                }    
            }
            for(int j=0; j<4; j++) {
                if(plants[j]==-1) {
                    res[i] = j+1;
                    break;
                }
            }
        }
        return res;
    }
};