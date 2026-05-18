class Solution {
public:
    bool helper(vector<int>& arr, int idx, vector<int>& vis ) {
        if(idx>=arr.size() || idx<0) return false;
        if(vis[idx] != -1) return false;
        if(arr[idx]==0) return true;
        vis[idx] = 1;
        return helper(arr, idx-arr[idx], vis) || helper(arr, idx+arr[idx], vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), -1);
        return helper(arr, start, vis);
    }
};