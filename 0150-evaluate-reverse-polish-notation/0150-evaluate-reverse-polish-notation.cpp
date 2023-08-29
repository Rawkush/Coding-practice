#define debug(x) cout<<#x<<" "<<x<<endl;
class Solution {
public:

  int evalOp(int a, int b, string op){
    if(op=="+") return b + a;
    if(op=="*") return a*b;
    if(op=="/") return b/a;
    if(op=="-") return  b-a;
    // if(op=="^") return pow(a, b);
    return 0;
  }

  bool isOp(string op){
    if( op == "+" || op == "-" || op == "*" || op == "/") return true;
    return false;
  }

  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(auto token: tokens){
      if(isOp(token)){
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        int res  = evalOp(num1, num2, token);
        // debug(res);

        st.push(res);
      }else st.push(stoi(token));
    }
    return st.top();
  }
};