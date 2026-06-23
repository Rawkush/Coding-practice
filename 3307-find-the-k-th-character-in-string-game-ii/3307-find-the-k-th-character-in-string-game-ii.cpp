class Solution {
public:
    int helper(long long k, long long s, vector<int>& op, int idx) {
        if(s==1) return 0;
        // if(idx == 0) return 0;
        if(k <= s/2) { // k is in left part current op is useless so ignore
            return helper(k, s/2, op, idx-1);
        } else {
            // if it is on right side then it means apply all previous operation
            int ans = helper(k -(s/2), s/2, op, idx-1);
            // cout<<ans;
            if(op[idx]==1) ans = (ans+1)%26;
            return ans;
        }
    }
    char kthCharacter(long long k, vector<int>& operations) {
        //since k is in long long we need only till that numer
        long long s = 1;
        int i = 0;
        for( ; i<operations.size(); i++) {
            s = s<<1;
            if(s>=k) break;
        }
        // long long s = 1LL << operations.size();
        // cout<<"Size "<<s<<endl;
        return helper( k , s , operations, i) + 'a';    
    }
};