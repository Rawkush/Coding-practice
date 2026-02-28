class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int c=0;
        while(ans>0) {
            if((ans&1 )!=0) c++;
            ans = ans>>1;
        }
        return c;
    }
};