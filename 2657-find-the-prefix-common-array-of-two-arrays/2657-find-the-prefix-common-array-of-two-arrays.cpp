class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int>m1, m2;
        vector<int> res;
        int ps =0;
        for(int i=0; i<A.size(); i++) {
            if(m2[A[i]] >0) ps++;
            m1[A[i]]++;
            if(m1[B[i]] >0) ps++;
            m2[B[i]]++;
            res.push_back(ps);
        }
        return res;
    }
};