class Solution {
public:
    void fillCache(int k, int n, vector<int>&cache) {
        for(int i=2; i*k<=n; i++) {
            cache[i*k] = 0;
        }
    }
    int countPrimes(int n) {
        vector<int> primeCache(n+1, -1);
        int count =0;
        for(int i=2; i<n; i++) {
            if(primeCache[i]==-1) {
                fillCache(i,n, primeCache);
            }
        }
        for(int i=2; i<n; i++) {
            if(primeCache[i] == -1) {
                count++;
            }
        }
        return count;
    }
};