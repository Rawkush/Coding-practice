class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int n = grid.size();
        int m = grid[0].size();
        int remid = grid[0][0] % x;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] % x != remid ) return -1;
            }   
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                arr.push_back(grid[i][j]);
            }   
        }
        sort(arr.begin(), arr.end());
        int median = arr[arr.size()/2];
        int ans = 0;
        for(auto ele: arr) {
            ans += abs(ele-median)/x;
        }
        return ans;
    }
};