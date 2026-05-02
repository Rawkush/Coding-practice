class Solution {
public:
    // check if next element can be connected with 
    bool isConnected(vector<vector<int>> &grid, int i, int j, char d) {
        int v = grid[i][j];
        if(v==1) {
            return (d == 'l' || d=='r');
        }
        if(v==2) {
            return (d=='u' || d =='d');
        }
        if(v==3) {
            return d=='l' || d=='d';
        }
        if(v==4) {
            return d=='d' || d=='r'; 
        }
        if(v==5) {
            return d=='u' || d=='l';
        } if(v==6) {
            return d=='u' || d=='r';
        }
        // switch(grid[i][j]) {
        //     case 1:
        //         return grid[r][c] != 2;
        //     case 2:
        //         return grid[r][c] != 1; 
        //     default: return true;
        // }
        return false;
    }
    /** blocked direction bd */
    bool dfs(vector<vector<int>> &grid, int r, int c, char bd,   bool first =false ) {
        if(r<0 || c <0 || r >= grid.size() || c >= grid[0].size()) return false;
        if(r==grid.size()-1 && c == grid[0].size()-1) return true;
        if(r==0 && c==0 && !first) return false; // loop
        int v = grid[r][c];
        if(v==1) {
            //means go right or left

            // if we go left check if bd is not left
            if(c-1 >=0 && bd!='l' && isConnected(grid,r, c-1, 'r')) {
                //for next cell it is right direction is blocked
                if( dfs(grid, r, c-1,'r')) return true;
            }

            // go right, nexr cell bd
            if(c+1 < grid[0].size() && bd!='r' && isConnected(grid, r, c+1, 'l')) {
                if(dfs(grid, r, c+1,'l')) return true;
            }
            
        }
        if(v==2) {
            //up or down
            //go up 
            if(r-1 >=0 && bd!='u' && isConnected(grid, r-1, c, 'd')) {
                if(dfs(grid, r-1, c,'d')) return true;
            }


            if(r+1 < grid.size() && bd!='d' && isConnected(grid, r+1, c, 'u')) {
                if( dfs(grid, r+1, c,'u')) return true;
            }    
        }
        if(v==3) {
            //left or down
            //left
            if(c-1 >=0 && bd!='l' && isConnected(grid, r, c-1, 'r')) {
                //for next cell it is right direction
                if(dfs(grid, r, c-1,'r')) return true;
            }

            //down
            if(r+1 < grid.size() && bd!='d' && isConnected(grid, r+1, c, 'u')) {
                //next cvell
                if( dfs(grid, r+1, c,'u')) return true;
            }

        }
        if(v==4) {
            //down right
            if(r+1 < grid.size() && bd!='d' && isConnected(grid, r+1, c, 'u')) {
                //next cvell
                if( dfs(grid, r+1, c,'u')) return true;
            }

            // go right, nexr cell bd
            if(c+1 < grid[0].size() && bd!='r' && isConnected(grid, r, c+1, 'l')) {
                if(dfs(grid, r, c+1,'l')) return true;
            }

        }
        if(v==5) {
            //left or up
                        //left
            if(c-1 >=0 && bd!='l' && isConnected(grid, r, c-1, 'r')) {
                //for next cell it is right direction
                if( dfs(grid, r, c-1,'r')) return true;
            }

                        //go up 
            if(r-1 >=0 && bd!='u' && isConnected(grid, r-1, c, 'd')) {
                if( dfs(grid, r-1, c,'d')) return true;
            }

        }
        if(v==6) {
            //up of right

            //go up 
            if(r-1 >=0 && bd!='u' && isConnected(grid, r-1, c, 'd')) {
                if( dfs(grid, r-1, c,'d')) return true;
            }
            if(c+1 < grid[0].size() && bd!='r' && isConnected(grid, r, c+1, 'l')) {
                if(dfs(grid, r, c+1,'l')) return true;
            }
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, 'a', true);
    }
};