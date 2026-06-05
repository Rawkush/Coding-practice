class Solution {
public:
    bool checkValidString(string s) {
       int c = 0;
       stack<int> bs; //bracket stack
       stack<int> ss; // st start

       for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') bs.push(i);
            if(s[i] == '*') ss.push(i);
            if(s[i] == ')') {
                if(!bs.empty()) bs.pop();
                else {
                    if(ss.empty()) return false;
                    int idx = ss.top();
                    if(idx < i) ss.pop();
                }
            }
            
       }

        while(!bs.empty() && !ss.empty()) {
            if(ss.top() < bs.top()) return false;
            ss.pop();
            bs.pop();
        }
        return bs.empty();
    }
};