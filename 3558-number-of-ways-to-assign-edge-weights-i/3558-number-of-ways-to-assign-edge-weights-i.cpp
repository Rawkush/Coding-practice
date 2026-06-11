class Solution {
public:
    int depth(unordered_map<int,vector<int>> &graph, unordered_set<int>&vis, int i) {
        if(vis.count(i) >0 || graph[i].size()==0) return 0;
        vis.insert(i);
        int d =0;
        for(auto x: graph[i]) {
            d = max(d, depth(graph, vis, x));
        }
        return d+1;
    }

    int countOdd(int n, int sum) {
        if(n==0) {
            if(sum%2==0) return 0;
            return 1;
        }
        int ans = 0;
        if(sum%2==0) sum=2;
        else sum =1;
        ans = (ans +countOdd(n-1, sum+1)) % 1000000007; //if we take
        ans = (ans +countOdd(n-1, sum+2)) % 1000000007; //if we take
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph; 
        for(auto x:edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        unordered_set<int> vis;
        int d = depth(graph, vis, 1);
        d--;
        // cout<<d;
        // int ans = countOdd(d, 0);
        int res =1;
        while(--d) {
            res = (res<<1)%1000000007;
        }
        return res;
    }
};