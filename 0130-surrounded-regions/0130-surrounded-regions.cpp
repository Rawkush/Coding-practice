class Solution {
public:

    void surround(vector<vector<char>>& board, queue<pair<int,int>>& q, vector<vector<bool>>& vis){
        int m = board.size();
        int n = board[0].size();
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            //top
            if(row>0 && board[row-1][col]=='O' && !vis[row-1][col]){
                vis[row-1][col]= true;
                q.push({row-1, col});
            }
            if(row<m-1 && board[row+1][col]=='O'&& !vis[row+1][col]){
                vis[row+1][col]= true;
                q.push({row+1, col});
            }
            if(col>0 && board[row][col-1]=='O'&& !vis[row][col-1]){
                vis[row][col-1]= true;
                q.push({row, col-1});
            }
            if(col<n-1 && board[row][col+1]=='O'&& !vis[row][col+1]){
                vis[row][col+1]= true;
                q.push({row, col+1});
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        // push all corners with 0 into queue  on hoizontal line
        for(int i=0; i<n; i++){
            //first row
            if(board[0][i]=='O'){
                vis[0][i] = true;
                q.push({0, i});
            }
            //last row
            if(board[m-1][i]=='O'){
                vis[m-1][i]=true;
                q.push({m-1, i});
            }
        }

        // vertical line
        for(int i=0; i<m; i++){
            //first col
            if(board[i][0]=='O'){
                vis[i][0] = true;
                q.push({i, 0});
            }
            if(board[i][n-1]=='O'){
                vis[i][n-1]= true;
                q.push({i, n-1});
            }
        }

        surround(board, q, vis);
        
        for(int i=0 ; i<m; i++){
            for(int j=0; j<n; j++ ){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j] ='X';
            }
        }
    }
};