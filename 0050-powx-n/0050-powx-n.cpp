class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double ans = x;
        long long p=1;
        while(p<abs((long)n)) {
            if(2*p <= abs((long)n)) {
                p = 2*p;
                ans = ans*ans;
            } else {
                p++;
                ans = ans*x;
            }
        }
        return n>=0? ans : ((double)1/ans);
    }
};