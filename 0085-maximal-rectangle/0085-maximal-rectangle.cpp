class Solution {
public:
    int ans = 0;
    void helper(vector<vector<char>>& matrix, int r, int c) {
        if(r<0 || c<0 || r>=matrix.size() || c>=matrix[0].size()) return;
        int mxAllowedColLen = INT_MAX;   
        for(int i=r; i<matrix.size(); i++) {
            if(matrix[i][c] == '0') return;
            int colLen = 0;
            while( c+ colLen <matrix[0].size() && matrix[i][c + colLen] =='1') colLen++;
            int height = i-r+1;
            mxAllowedColLen = min(mxAllowedColLen, colLen);
            int area = height*mxAllowedColLen;
            ans = max(area, ans);
        }
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        int mx = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]=='1') helper(matrix, i, j);
            }
        }
        return ans;
    }
};