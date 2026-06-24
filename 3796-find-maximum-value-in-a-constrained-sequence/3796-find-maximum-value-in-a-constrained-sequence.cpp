class Solution {
public:
    void print( vector<int> &arr) {
        for(auto x: arr) cout<<x<<" ";
        cout<<endl;
    }
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> arr(n, 0);
        unordered_map<int,int>rest;
        for(auto x:restrictions) {
            rest[x[0]] = x[1];
        }

        for(int i=1; i<arr.size(); i++) {
            int h1 = arr[i-1] + diff[i-1];
            if(rest.count(i) > 0) {
                // if restrtcition
                int h2 = rest[i];
                arr[i] = min(h1, h2);
            }
            else arr[i] = h1;          
        }

        // print(arr);
        for(int i=arr.size()-2; i>0; i--) {
            int d = abs(arr[i+1] - arr[i]);
            if(d > diff[i]) arr[i] = arr[i+1] + diff[i];
        }
        // print(arr);

        int mx = 0;
        for(int i=0; i< arr.size(); i++) {
            mx = max(mx, arr[i]);
        }
        return mx;
    }
};