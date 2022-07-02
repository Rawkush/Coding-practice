#include<iostream>
#include<stack>
using namespace std;

void inserAtBottom(stack<int> &st, int data){
	stack<int> tmp;
	while(!st.empty()){
		tmp.push(st.top());
		st.pop();
	}
	 st.push(data);
	while(!tmp.empty()){
		st.push(tmp.top());
		tmp.pop();
	}
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
