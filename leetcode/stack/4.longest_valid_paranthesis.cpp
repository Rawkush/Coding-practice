#include<iostream>
#include<stack>
using namespace std;


class Pair{
  public:
  int count;
  char bracket;
  Pair(int count){
    this->count = count;
    bracket = '\0';
  }
  Pair(char bracket){
    this->bracket = bracket;
    this->count = 0;
  }
};

int longestValidParentheses(string s) {
  if(s.length()<1) return 0; // base case

  stack<Pair*> st;
  int count = 0;

  for(int i = 0; i < s.size(); i++){
    if(s[i] == '('){
      st.push(new Pair('('));
      cout<<"push"<<" ( "<<endl;
      continue;
    }

    if(st.empty() && s[i] == ')') continue;  // skip ) if they are at beginning

    Pair *top = st.top();
    if(top->bracket == '('){
      st.pop();
      st.push(new Pair(2));
      cout<<"pair found adding 2 to stack"<<endl;
      continue;
    }
    bool check = true;
    while(!st.empty()){
      //top->bracket!='('
      top=st.top();

      /** Pair fount */
      if(top->bracket == '('){
        st.pop();
        check = false;
        if(count>0){
          cout<<"pair found, repushing the old count "<<count<<endl;
          st.push(new Pair(count));
        }
        cout<<"pair found adding 2 to stack"<<endl;
        st.push(new Pair(2));
        break;
      }
      /** no pair found, but fount )  */
      if(top->bracket == ')'){
        check = false;
        if(count>0){
          cout<<") found repushing old count "<<count<<endl;
          st.push(new Pair(count));
        }
        st.push(new Pair(')'));
        break;
      }
      //if reached here it means number is stored
      st.pop();
      count=count+top->count;
      cout<<" number found new count is "<<count <<endl;
    }
    if(check){
      st.push(new Pair(count));
      st.push(new Pair(')'));
    }
    count=0;
  }

  int max=0;
  while(!st.empty()){
    Pair *top= st.top();
    st.pop();
    if(top->bracket == '\0'){
      count=count+top->count;
      if(max<count) max=count;
    }else{
      count=0;
    }
  }
  // while(!st.empty()){
  //   cout << st.top()->count<<" ";//>>
  //   st.pop();
  // }
  return max;
}


int main(){
  cout<<longestValidParentheses("((()))())");
  return 0;
}
