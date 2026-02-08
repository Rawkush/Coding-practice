// PRIMS ALGO
class Solution {
public:

    int getWeight(vector<vector<int>>& points, int i, int j) {
       return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); 
    }
    void exploreAllPaths(vector<vector<int>>& points, int idx, vector<bool>&vis, vector<int> &weight ) {
      for(int i=0; i<points.size(); i++) {
        if(i==idx || vis[i]) continue;
        int cw = weight[i]; //current weight
        int w = getWeight(points, idx, i); //weight from  idx node to ith node
        if(w<cw) {
            weight[i] = w;
        }
      } 
    }

    int minCostVertex(vector<int> &weight, int idx, vector<bool>&vis) {
        int minIndex = -1;
        int minWeight = INT_MAX;
        for(int i=0; i<weight.size(); i++) {
            if(vis[i]) continue;
            if(weight[i]<minWeight) {
                minWeight = weight[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        /**
        since building a edgelist wil take O(N^2), and so would if we go that on run time for calculting the distance while solving, so going with second approach
        NOTE: we can assume each coordinate as a vertex, and can denote it like 
        veterx => Vi  where Vi has coordinate X1, Y1
        */
        int n = points.size();
        vector<bool> vis(n , false);
        vector<int> weight(n, INT_MAX);
        weight[0] = 0;
        int cost = 0, node = 0;
        for(int i=0; i<n; i++) {
            /**
            Why did not use PQ? I did but it gave TLE, bcz 
            it is a connected graph, and so had to push too much data
            and discard everything again for every path exploration
            else size keeps increasing and so does runtime TC 
            */
            node = minCostVertex(weight, node, vis);
            vis[node] = true;
            cost += weight[node];
            exploreAllPaths(points, node, vis, weight);
        }
        return cost;
    }
};