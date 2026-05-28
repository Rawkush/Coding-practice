class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {
        if (s[0] == '1' || s.back() == '1') return false;
        queue<int> q;
        vector<int> vis(s.size(), 0);
        q.push(0);
        int farthest = 0;  // rightmost index already scanned

        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            int w = max(idx+minJump, farthest+1);
            for(int i=w; i<=idx+maxJump && i<s.size(); i++) {
                if(s[i]=='1') continue;
                if(vis[i]) continue;
                if(i==s.size()-1 ) return true;
                vis[i]=1;
                q.push(i);
            }
            farthest = max(farthest, idx + maxJump);
        }
        return false;
    }
};