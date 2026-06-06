class Solution {
public:
    bool isSafeNode(vector<vector<int>>& graph, vector<int> &vis, int n,  vector<int> &safeNodes) {
        if(safeNodes[n]!=-1) return safeNodes[n] ==1;
        if(graph[n].size()==0) return true;
        for(auto x:graph[n]) {
            if(vis[x]) {
                safeNodes[x] = 0;
                return false;
            }
            vis[x] =1;
            if(!isSafeNode(graph,vis, x, safeNodes )) {
                vis[x] = 0;
                return safeNodes[x] =false;
            }
            vis[x] =0;
        }
        return safeNodes[n]=true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        vector<int> vis(graph.size(), 0); 
        vector<int> safeNodes(graph.size(), -1);

        for(int i=0; i<graph.size(); i++) {
            if(safeNodes[i]==1) res.push_back(i);
            else if(isSafeNode(graph, vis, i, safeNodes )) {
               safeNodes[i] = 1;
               res.push_back(i);
            } else safeNodes[i] = 0; // unsafe node
        }
        return res;
    }
};