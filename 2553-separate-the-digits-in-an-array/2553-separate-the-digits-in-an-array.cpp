class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string s = "";
        for(auto x: nums) {
            s+=to_string(x);
        }
        vector<int> res;
        for(int i=0; i<s.size(); i++) {
            res.push_back(s[i] - '0');
        }
        return res;
    }
};