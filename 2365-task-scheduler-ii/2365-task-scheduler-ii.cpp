class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long> mp;
        long long ans = 0;
        long long idxOffset =0;
        for(int i=0; i<tasks.size(); i++) {
            int t = tasks[i];
            if(mp.count(t)<=0) {
                ans++;
            } 
            else if(i+idxOffset>=mp[t]){ 
                ans++;
            }
            else {
                ans += mp[t] - (i + idxOffset) + 1;
                idxOffset += mp[t] - (i + idxOffset);
            }
            mp[t] = i+space+1+idxOffset;
        }
        return ans;
    }
};