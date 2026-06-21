class Solution {
public:
  int pre(string ch){
    if(ch=="^")return 3;
    else if(ch=="*" || ch=="/")return 2;
    else if(ch=="+" || ch=="-")return 1;
    return 0;
  }

    long long evalOp(long long a, long long b, string op){  // ← long long
        if(op=="+") return b + a;
        if(op=="*") return b * a;
        if(op=="/") return b / a;
        if(op=="-") return b - a;
        if(op=="^") return (long long)pow((double)b, (double)a);
        return 0;
    }
    
  bool isOp(string op){
    if( op == "+" || op == "-" ||
      op == "*" || op == "/" ||
      op=="^" || op=="(" || op==")"
    ) return true;
    return false;
  }

    vector<string> tokenize(string s){
        vector<string> tokens;
        string str = "";
        for(auto x : s){
            if(x == ' ') continue;
            string t(1, x);
            if(t=="+" || t=="-" || t=="*" ||
            t=="/" || t=="^" || t=="(" || t==")"){
                if(str.size() > 0){
                    tokens.push_back(str);
                    str = "";
                }
                // unary minus: "-" at start, or after "(" or after another operator
                if(t == "-" || t == "+"){
                    bool unary = tokens.empty()
                            || tokens.back() == "("
                            || (isOp(tokens.back()) && tokens.back() != ")");
                    if(unary) tokens.push_back("0");
                }
                tokens.push_back(t);
            } else {
                str += t;
            }
        }
        if(str.size() >= 1) tokens.push_back(str);
        return tokens;
    }

  // string infixToPostfix(string exp){
  //   stack<char> st;
  //   int n= exp.length();
  //   string output=""; 

  //   for(int i=0; i< n;i++){
  //     char c= exp[i];
      
  //     if(c=="*"|| c=="/" || c=="+" || c== "-" || c=="^"){
          
  //         if(st.empty()){
  //             st.push(c);
  //             continue;
  //           }
          
        
  //         while (!st.empty() && pre(c)<=pre(st.top())) {
  //               output += st.top();
  //               st.pop();
  //             }
        
          
  //         st.push(c);
            
  //     }
  //     else if(c==")"){
  //         while(st.top()!="("){
  //             output+=st.top();
  //             st.pop();
  //         }
  //         st.pop();
  //     }
  //     else if(c=="("){
  //         st.push(c);
  //     }
  //     else{
  //         output+=c;
  //     }
  //   }

  //   while(!st.empty()){
  //       output+=st.top();
  //       st.pop();
  //   }
  //   return output;
  // }

  string trim(string s){
    string pre ="";
    for(int i=0; i<s.size(); i++){
      if(s[i]== ' ') continue;
      else pre+=s[i];
    }
    return pre;
  }

 
  int calculate(string s) {
    string expr = trim(s);
    vector<string> infix = tokenize(expr);
    stack<string> ost;
    stack<long long> nums;
    nums.push(0);
    for(int i=0; i<infix.size(); i++){
      string c = infix[i];
      if(isOp(c)){
        if(c=="(" || ost.empty()){
          ost.push(infix[i]);
          continue;
        }
        if(c==")"){
          //pop until ( is found and also keep evaluting the data from nums       
          while (!ost.empty() && ost.top()!="(") {
            int num1 = 0;
            int num2 = 0;
            if(!nums.empty()){
              num1 = nums.top();
              nums.pop();
            }
            if(!nums.empty()){
              num2 = nums.top();
              nums.pop();
            }
            int res = evalOp(num1, num2, ost.top());
            nums.push(res);
            // output += st.top();
            ost.pop();
          }
          ost.pop(); // this will remove "(" so no eval
        }
        else{
          while (!ost.empty() && pre(c)<=pre(ost.top())) {
            if(pre(c)==pre(ost.top()) && c == "^"){
              break;
            }
            int num1 = 0;
            int num2 = 0;
            if(!nums.empty()){
              num1 = nums.top();
              nums.pop();
            }
            if(!nums.empty()){
              num2 = nums.top();
              nums.pop();
            }
            int res = evalOp(num1, num2, ost.top());
            nums.push(res);
            ost.pop();
          }
          ost.push(c);
        }
      }else{
        nums.push(stoll(c));  // ← was stoi
      }
      // if(ost.empty() && isOp(infix[i]) ){
      //   ost.push(infix[i]);
      //   continue;
      // }



    }

    while(!ost.empty()){
      int num1 = 0;
      int num2 = 0;
      if(!nums.empty()){
        num1 = nums.top();
        nums.pop();
      }
      if(!nums.empty()){
        num2 = nums.top();
        nums.pop();
      }
      int res = evalOp(num1, num2, ost.top());
      nums.push(res);
      // output += st.top();
      ost.pop();
    }
    return nums.top();
  }
};