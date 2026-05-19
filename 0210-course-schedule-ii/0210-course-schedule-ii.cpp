class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        vector<int> ndegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        vector<int> res;
        for(auto &x:p) {
            ndegree[x[0]]++; 
            adj[x[1]].push_back(x[0]);
        }
        queue<int>  q;
        for(int i=0; i<numCourses; i++) {
            if(ndegree[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto x: adj[node]) {
                ndegree[x]--;
                if(ndegree[x]==0) q.push(x);
            }
        }
        return res.size()==numCourses ? res : vector<int>(0);
    }
};