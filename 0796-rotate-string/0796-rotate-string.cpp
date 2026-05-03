class Solution {
public:
    bool h(string &s, string &goal, int p) {
        int k=0;
        for(int i=p; i<s.size(); i++, k++) {
            if(s[i]!=goal[k]) return false;
        }
        for(int i=0; i<p; i++, k++) {
            if(s[i]!=goal[k]) return false;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=s.size()-1; i>=0; i--) {
           if(h(s,goal,i)) return true;
        }
        return false;
    }
};