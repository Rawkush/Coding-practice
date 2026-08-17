class Solution {
public:
    int findCol(vector<vector<int>>& matrix, int target, int l, int r) {
        if(l>r) return l;
        int mid = (l+r)/2;
        if(matrix[0][mid]==target) return mid;
        if(matrix[0][mid] > target) {
            return findCol(matrix, target, l, mid-1);
        }
        if(l==r) return l;
        return findCol(matrix, target, mid+1, r);
    }

    bool findRow(vector<vector<int>>& matrix, int target, int l, int r, int c) {
        if(l>r) return false;
        int mid = (l+r) / 2;
        if(matrix[mid][c] == target) return true;
        if(matrix[mid][c] > target) {
            return findRow(matrix, target, l, mid - 1, c);
        } else {
            return findRow(matrix, target, mid + 1, r, c);
        }
    }
  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = findCol(matrix, target, 0, matrix[0].size()-1);
        while (col >= 0) {
            //worst case N*logn
            if (findRow(matrix, target, 0, matrix.size() - 1, col)) {
                return true;
            }
            col--; 
        }
        return false;
    }
};