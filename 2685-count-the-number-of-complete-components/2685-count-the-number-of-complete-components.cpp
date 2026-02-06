/*** UNION FIND */

class DisjointSet {
public:
    unordered_map<int, int> parent, size, edge;
    int findP(int n) {
        if (parent.find(n) ==
            parent.end()) { // if nothing then it is istelf parent node
            size[n] = 1;    // A new node starts with 1 vertex
            edge[n] = 0;    // A new node starts with 0 edges
            return parent[n] = n;
        }
        if (n == parent[n])
            return n;
        return parent[n] = findP(parent[n]); // path compression
    }
    /** add edge to set */
    void unionBySize(int u, int v) {
        int p1 = findP(u);
        int p2 = findP(v);
        if (p1 == p2) {
            edge[p1]++;
            return;
        };
        if (size[p1] > size[p2]) {
            parent[p2] = p1;
            size[p1] += size[p2];
            edge[p1] += edge[p2] + 1; // existing edge + new edge
        } else {
            parent[p1] = p2;
            size[p2] += size[p1];
            edge[p2] += edge[p1] + 1; //existing edge + new edge
        }
    }

    int getTotalEdges(int node) { return edge[node]; }
    int getTotalVertex(int node) { return size[node]; }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet dj;
        for (auto x : edges) {
            dj.unionBySize(x[0], x[1]);
        }
        unordered_set<int> parents;
        /** all disjoint nodes  */
        for (int i = 0; i < n; i++) {
            parents.insert(dj.findP(i));
        }

        int count = 0;
        for (auto x : parents) {
            int e = dj.getTotalEdges(x);
            int v = dj.getTotalVertex(x);
            if((v*(v-1))/2==e)count++;
        }
        return count;
    }
};

/*** with normal recursion */
// class Solution {
// public:

//     void createGraph(unordered_map<int, vector<int>>&graph,
//     vector<vector<int>>&edge) {
//         for(auto x: edge) {
//             int u = x[0];
//             int v = x[1];
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }
//     }

//     pair<int, int> dfs(unordered_map<int, vector<int>>& graph, int n,
//     vector<int>&vis, unordered_map<int, unordered_map<int,int>> &pvis ) {
//         vector<int> neighbors = graph[n];
//         int cv = 1; //vertex count
//         int ce = 0; //edge count
//         vis[n] = 1;
//         for(auto x: neighbors) {
//             if(!pvis[n][x]) {
//                 pvis[n][x] = 1;
//                 pvis[x][n] = 1;
//                 ce++;
//             }
//             if(!vis[x]) {
//                vis[x] = 1;
//                pair<int,int> p = dfs(graph, x, vis, pvis);
//                cv+= p.first;
//                ce+=p.second;
//             }
//         }

//         return { cv, ce };
//     }

//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         unordered_map<int, vector<int>> graph;
//         createGraph(graph, edges);
//         // printg(graph, n);
//         int count = 0;
//         unordered_map<int, unordered_map<int,int>> pvis; // to check all
//         edges i.e paths vector<int> vis(n, 0); // to tell independent graph
//         for(int i=0; i<n; i++) {
//             if(vis[i]) continue;
//             pair<int, int> p = dfs(graph, i, vis, pvis);
//             int v = p.first;
//             int e = p.second;
//             if(e==(v*(v-1))/2) count++;
//             cout<<v<<" "<<e<<endl;
//         }
//         return count;
//     }
// };