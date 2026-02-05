class DisjointSet {
    public: 
    unordered_map<int, int> parent, rank;

    int findParent(int node) { 
        if(node == parent[node]) return node;
        if(parent[node]==0) return parent[node] = node; // if parent does not exists, it means it is a new node and is parent itself
        return parent[node] = findParent(parent[node]); // path compression
    }
    /** Add edge to disjoint set */
    void unionByRank(int u, int v) {
        int p1 = findParent(u);
        int p2 = findParent(v);
        if(p1 == p2) return;
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1]++;
        } else {
            parent[p1] = p2;
            rank[p1]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet dj;
        vector<int> res;
        for(auto edge: edges) {
            int p1 = dj.findParent(edge[0]);
            int p2 = dj.findParent(edge[1]);
            if(p1 == p2) {
                res.clear();
                res.push_back(edge[0]);
                res.push_back(edge[1]);
            } else {
                dj.unionByRank(edge[0], edge[1]);
            }
        }

        return res;
    }
};