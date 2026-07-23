class Solution {
public:
    string smallestSubsequence(string s) {
          stack<char> st; // we will store 'a
        unordered_map<char,int> cmp; //character map
        unordered_map<char,int> isPresent; //c

        for(auto x:s)cmp[x]++;

        int uniqueCharLen = cmp.size();
        for(int ch: s) {
            cmp[ch]--;

            if(isPresent[ch]) continue; // already present skip
            isPresent[ch]=1; 
            
            while(!st.empty()) {
                char top = st.top();
                if(top == ch) break;
                if(ch > top) {
                    st.push(ch);
                    break;
                }
                if(top > ch && cmp[top] >= 1) {
                    st.pop();
                    isPresent[top] = 0;
                } else {
                    // it means top>ch and current top cannoit be removed
                    st.push(ch);
                }
            }
            if(st.empty()){
                st.push(ch);
                continue;
            }
        }
        
        // print(st);
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};