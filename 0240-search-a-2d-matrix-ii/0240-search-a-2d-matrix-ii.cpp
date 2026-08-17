class Solution {
public:
  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;
        int j=0;
        int i=n;
        while(i>=0 && j<=m) {
            if(matrix[i][j]==target) return true;
            if(target > matrix[i][j]) {
               j++;
            } else {
                i--;
            }            
        }
        return false;
    }
};