class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int c =0;
        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] ==1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        // find poisition
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] ==1 && row[i]==1 && col[j]==1) c++; 
            }
        }
        return c;
    }
};