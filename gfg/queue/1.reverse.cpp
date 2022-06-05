#include<iostream>
#include<queue>
using namespace std;

queue<int> rev(queue<int> input)
{
  /** iterative solution */
    //   stack<int> s;
    // while(!input.empty()){
    //     s.push(input.front());
    //     input.pop();
    // }
    // while(!s.empty()){
    //     input.push(s.top());
    //     s.pop();
    // }
    // return input;

    // add code here.
  if(input.size()<=1){
    return input;
  }
  int front = input.front();
  input.pop();
  queue<int>tmp=rev(input);
  tmp.push(front);
  return tmp;
}

int main(){

  return 0;
}