// class Node {
//     int data;
//     unordered_nod
// }
class Solution {
public:

    void add( unordered_set<string> &set, int num) {
        string s = to_string(num);
        string ts = "";
        for(int i=0; i<s.size(); i++) {
            ts+=s[i];
            set.insert(ts);
        }
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> set;
        for(auto x:arr1) {
            add(set, x);
        }
        int mx =0;
        for(auto x: arr2) {
            string s = to_string(x);
            string ts = "";
            for(int i=0; i<s.size(); i++) {
                ts+=s[i];
                if(set.find(ts)!=set.end()) {
                   mx = max(mx,i+1); 
                }
            }
        }
        return mx;
    }
};