class Solution {
public:

  void print(stack<string> st){
    while(!st.empty()){
      cout<<st.top()<<" ";
      st.pop();
    }
    cout<<endl;
  }

  int longestValidParentheses(string s) {
    if(s.size()<=0) return 0;
    stack<string> st;
    int mx = 0;
    for(int i=0; i<s.size(); i++){
      if(s[i]=='('){
        // string str(1, '(');
        st.push("(");
        continue;
      }
      string str = "";
      while(!st.empty() && st.top()!="(" && st.top()!=")"){
        str =  st.top() + str;
        st.pop();
      }
      if(st.empty()){ // ( not found for ) so malformed
        if(str.size()>0) st.push(str);
        st.push(")");
        continue;
      }
      if(st.top()=="("){
        str = st.top() + str +")";
        st.pop();
        st.push(str);
        continue;
      }
      //else
      if(str.size()>0) st.push(str);
      st.push(")");
    }

    print(st);

    int count = 0;
    while(!st.empty()){
      if(st.top()==")" || st.top()=="("){
        mx = max(mx,count);
        count =0;
        st.pop();
        continue;
      }
      count += st.top().size();
      st.pop();
    }
    mx = max(count, mx);
    return mx;
  }
};