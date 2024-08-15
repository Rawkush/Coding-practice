class Solution {
public:

    void dfs(int st, vector<vector<int>>& isConnected, vector<bool>&isVisited){
        int n = isConnected.size();
        if(st>= n) return;
        for(int i=0; i<n; i++){
            if(isConnected[st][i]==1 && !isVisited[i]){
                isVisited[i] = true;
                dfs(i, isConnected, isVisited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalP =0;
        int n = isConnected.size();
        vector<bool> isVisited(n, false);
        /** 
        *  Check each vertex
        */
        for(int i=0; i<n; i++){
           if(isVisited[i]) continue;
           totalP++;
           dfs(i, isConnected, isVisited);
        }
        return totalP;
    }
};