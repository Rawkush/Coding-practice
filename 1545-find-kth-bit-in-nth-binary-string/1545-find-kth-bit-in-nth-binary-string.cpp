class Solution {
public:
    // string reverse(const string &s) {
    //     string ss = "";
    //     for (auto x : s) {
    //         ss = x + ss;
    //     }
    //     return ss;
    // }
    string invert(string& s) {
        string ss = "";
        for (auto x : s) {
            if (x == '1')
                ss += '0';
            else
                ss += '1';
        }
        return ss;
    }
    string helper(int n, int k, string &s) {
        if (n <= 0 || s.size() >= k)
            return s;
        string tmp = s;
        reverse(tmp.begin(), tmp.end() );

        s = s + "1" + invert(tmp);
        return helper(n-1, k, s);
        // return ss;
    }
    char findKthBit(int n, int k) {
        string s ="0";
        s = helper(n, k, s);
        
        return s[k - 1];
    }
};