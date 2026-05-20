class Solution {
public:
    void helper(int l, int r, string p, vector<string>& res) {
        if(r>l) return; // now we cannot balance the string
        if(l==0 && p!="") {
            res.push_back(p);
        }
        helper(l--, r+1, p+"(", res);
        if(r>0) helper(l, r-1, p+")", res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, "", res);
        return res;
    }
};