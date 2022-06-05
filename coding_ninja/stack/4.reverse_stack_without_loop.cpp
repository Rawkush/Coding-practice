#include<iostream>
#include<stack>
using namespace std;

void inserAtBottom(stack<int> &st, int data){
	if(st.empty()){
		st.push(data);
		return;
	}
	int top=st.top();
	st.pop();
	inserAtBottom(st,data);
	st.push(top);
}

void reverseStack(stack<int> &input) {
	if(input.empty()) return;
	int top = input.top();
	input.pop();
	reverseStack(input);
	inserAtBottom(input, top);
}


int main(){

  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  stack<int> s2;
  reverseStack(s);

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
}
