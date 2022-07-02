#include<iostream>
#include<stack>
using namespace std;


void reverseStack(stack<int> &input, stack<int> &extra) {
  if(input.empty() || input.size()==1){
    return;
  }
  int s= input.size();
  for(int i=0; i<s; i++){
    int top = input.top();
    input.pop();

    for(int j=0; j<input.size()-i;){
      //transfer all data from input to extra
      extra.push(input.top());
      input.pop();
    }
    //push top data now
    input.push(top);
    //push extra databack into input
    while(!extra.empty()){
      input.push(extra.top());
      extra.pop();
    }
  }
}

int main(){
  stack<int> input;
  stack<int> extra;
  input.push(1);
  input.push(2);
  input.push(3);
  input.push(4);
  reverseStack(input, extra);

  while(!input.empty()){
    cout<<input.top()<<" ";
    input.pop();
  }
  return 0;
}