class Solution {
public:

    int findMaxSquare(vector<vector<char>>& matrix, int i, int j, vector<vector<int>> &mem) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(i>=m || j>= n ) return 0;
        if(matrix[i][j] =='0') return 0;
        if(mem[i][j]!=-1) return mem[i][j];
        int a =  findMaxSquare(matrix, i, j+1, mem);
        int b =  findMaxSquare(matrix, i+1, j, mem);
        int c =  findMaxSquare(matrix, i+1, j+1, mem);
        return mem[i][j] =min(a, min(b,c)) + 1;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mx = 0;
        vector<vector<int>> mem(m, vector<int>(n, -1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                //from current index find all squares
                int slen = findMaxSquare(matrix, i, j, mem);
                mx = max(mx, slen);
            }
        }
        return mx*mx;
    }
};