class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') {
                st.push("(");
            } else if(s[i] != ')') {
                st.push(string(1, s[i])); // Fixed
            } else {
                // s[i] == ')'
                string tmp = "";
                while(!s.empty()) {
                    string s = st.top();
                    st.pop();
                    if(s == "(") break;
                    tmp = s + tmp;
                }
                reverse(tmp.begin(), tmp.end());
                st.push(tmp);
            }
        }
        string tmp ="";
        while(!st.empty()) {
            tmp = st.top() + tmp;
            st.pop();
        }
        return tmp;
    }
};