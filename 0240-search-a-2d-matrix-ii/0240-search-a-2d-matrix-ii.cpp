class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int target, int r1, int r2, int c1, int c2) {
        if (r1 > r2 || c1 > c2) return false;
        
        int nr = r1 + (r2 - r1) / 2;
        int nc = c1 + (c2 - c1) / 2;
        
        if (matrix[nr][nc] == target) return true;
        
        if (target > matrix[nr][nc]) {
            // Search Top-Right, Bottom-Left, and Bottom-Right
            return helper(matrix, target, r1, nr, nc + 1, c2) ||
                   helper(matrix, target, nr + 1, r2, c1, nc) ||
                   helper(matrix, target, nr + 1, r2, nc + 1, c2);
        } else {
            // Search Top-Left, Top-Right, and Bottom-Left
            return helper(matrix, target, r1, nr - 1, c1, nc - 1) ||
                   helper(matrix, target, r1, nr - 1, nc, c2) ||
                   helper(matrix, target, nr, r2, c1, nc - 1);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return helper(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
};