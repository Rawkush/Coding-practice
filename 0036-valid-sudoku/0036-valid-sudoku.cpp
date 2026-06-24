class Solution {
public:
    
    bool checkSmallBox(vector<vector<char>>& board, int r, int c) {
        set<char> s;
        r = r*3;
        c = c*3;
        for(int i=r; i<r+3; i++) {
            for(int j=c; j<c+3; j++) {
                char c = board[j][i];
                if( c =='.') continue;
                if(s.count(c) >0) return false;
                s.insert(c);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        //check row
        for(int i=0; i<n; i++) {
            set<char> s;
            for(int j=0; j<n; j++) {
                char c = board[i][j];
                if( c =='.') continue;
                if(s.count(c) >0) return false;
                s.insert(c);
            }
        }
        //checl col
        for(int i=0; i<n; i++) {
            set<char> s;
            for(int j=0; j<n; j++) {
                char c = board[j][i];
                if( c =='.') continue;
                if(s.count(c) >0) return false;
                s.insert(c);
            }
        }

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(!checkSmallBox(board, i, j)) return false;
            }
        }
        return true;
    }
};