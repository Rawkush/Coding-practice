class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> isP(26,0);
    vector<int> listidx(26,0);
    stack<char> st;
    for(int i=0; i<s.size(); i++){
     listidx[s[i]-'a'] = i;
    }

    for(int i=0; i<s.size(); i++){
      char c =s[i];
      int cn = s[i]-'a';
      if(isP[cn]) continue;
      if(st.empty()){
        isP[cn] = 1;
        st.push(c);
        continue;
      }

      int tn = st.top() -'a'; // top in num
      char t = st.top();
      while(!st.empty() && tn>cn && listidx[tn]>i ){
        // cout<<t<<" ";
        isP[tn] = 0;
        st.pop();
        if(!st.empty()){
          tn = st.top()-'a';
        }
      }
      st.push(c);
      isP[cn]=1;
    }

    string res="";
    while(!st.empty()){
      res =  st.top() + res;
      st.pop();
    }
    return res;
  }
};