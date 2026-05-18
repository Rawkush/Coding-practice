class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()<=1) return 0;
        queue<int> q;
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }

        q.push(0);
        int step =0;
        vector<int> vis(arr.size(), 0);
        vis[0]=1;
        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; i++) {
                int idx = q.front();
                q.pop();
                if(idx == arr.size()-1) return step; 
                if(idx>0 && !vis[idx-1]) {
                    q.push(idx-1);
                    vis[idx-1] =1;
                }
                if(idx+1<arr.size() && !vis[idx+1]) {
                    if(idx+1 == arr.size()-1) return step+1;
                    q.push(idx+1);
                    vis[idx+1] =1;
                }

                vector<int> &neighbors = mp[arr[idx]];

                for(int neighbor : neighbors) {
                    if(neighbor == arr.size()-1) return step+1;

                    if(!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
                mp.erase(arr[idx]);
            }
            step++;
        }
        return step;
    }
};