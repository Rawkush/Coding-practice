#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here
  // for(int i = 0; i < input.size(); i++){
  //   input.push(input.front());
  //   input.pop();
  // }
  if(input.size()<=1){
    return;
  }
  int front = input.front();
  input.pop();
  reverseQueue(input);
  input.push(front);
}

int main(){
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  reverseQueue(q);
  while(!q.empty()){
    cout << q.front() <<" ";
    q.pop();
  }
  return 0;
}