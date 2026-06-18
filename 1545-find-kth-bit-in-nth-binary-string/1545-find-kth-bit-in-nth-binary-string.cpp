class Solution {
public:

    char helper(int si, int k, int slen) {
        if(si==1) return '0';
        int mid = (slen/2) + 1;
        if(mid == k) return '1';
        if(k>mid) {
            //flip if on right side
            return helper(si-1, slen-k + 1, mid-1)=='1'? '0' : '1';
        }
        else {
            return helper(si-1, k, mid-1);
        }
    }

    char findKthBit(int n, int k) {
        /**
        *   if you see s0 =. 0
        * s1 = s0 + 1 + reverse(inert(s0));
        * there len(si) = len(si-1) + 1 + len(si-1);
        * => 2*len(si-1) + 1 
        */
        int slen=0;
        int i=1;
        for( ; i<=n; i++) {
            slen = 2*slen + 1;
            if(slen>=k) break;
        }

        return helper(i, k, slen);
    }
};