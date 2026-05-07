class Solution {
public:
    void print(vector<vector<char>>& boxGrid) {
        for(int i=0; i<boxGrid.size(); i++) {
            for(int j=0; j<boxGrid[0].size(); j++) {
               cout<<boxGrid[i][j]<<" ";
            }
            cout<<endl;
        }

    }

    // assume gravity is there pulling items on right
    void gravitySideways(vector<char>& arr) {
        //two pointers one point to gem other try to find emptry space and we swap
        int i=0, j=0;
        int n =arr.size();
        while(i<n && j<n) {
            //find first GEM
            while(i<n && arr[i]!='#' ) i++;
            j=i; // j will after i so doing this
            while(j<n && arr[j]=='#') j++;
            if(i>=n || j>=n) return;
            if(arr[j]=='*') {
                i=j; // above items can be moved
            }
            else swap(arr[i], arr[j]);
        }
        
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> res(m, vector<char>(n, '.'));
        
        for(auto &x: boxGrid) {
            gravitySideways(x);
        }

        for(int i=n-1, k=0; i>=0; i--, k++) {
            for(int j=0; j<m; j++) {
                res[j][k] = boxGrid[i][j];
            }
        }
        return res;
    }
};