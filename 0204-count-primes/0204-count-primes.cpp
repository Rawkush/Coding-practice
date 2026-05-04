class Solution {
public:

    int countPrimes(int n) {
        vector<bool> primeCache(n, true); //assume be default all are prime
        if(n==0) return 0;
        primeCache[0] = primeCache[1] = false;

        for(int i=2; i<n; i++) {
            if(primeCache[i]) {
                for(int j=2; i*j<n; j++) {
                    primeCache[i*j] = false;
                }
            }
        }
        return count(primeCache.begin(), primeCache.end(), true);
    }
};