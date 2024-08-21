class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        vector<vector<int>> res(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    isVisited[i][j] =true;
                }
            }
        }

        int d=0;
        while(!q.empty()){
            int s = q.size(); // all items in same level
            for(int i=0; i<s; i++){
                pair<int,int> p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;
                res[r][c] = d;
                // up
                if(r>0 && !isVisited[r-1][c]){
                    q.push({r-1, c});
                    isVisited[r-1][c] = true;
                }
                //down1
                if(r<m-1 && !isVisited[r+1][c]){
                    q.push({r+1, c});
                    isVisited[r+1][c] = true;
                }
                //left
                if(c>0 && !isVisited[r][c-1]){
                    q.push({r, c-1});
                    isVisited[r][c-1] = true;
                }
                //down
                if(c<n-1 && !isVisited[r][c+1]){
                    q.push({r, c+1});
                    isVisited[r][c+1] = true;
                }
            }
            d++;
        }

        return res;
    }
};