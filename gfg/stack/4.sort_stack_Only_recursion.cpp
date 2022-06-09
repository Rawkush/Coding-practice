#include <iostream>
#include <stack>

using namespace std;

int getMax(stack<int> &s){
   if(s.size()<=1) {
     int min = s.top();
     s.pop();
     return min;
   };
   int top = s.top();
   s.pop();
   int min = getMax(s);
   if(top<min){
     s.push(top);
     return min;
   }
   s.push(min);
   return top;
}


void sort(stack<int> &s){
  if(s.size()<=1) {
    return;
  }
  int max= getMax(s);
  sort(s);
  s.push(max);
}


int main(){

  stack<int> s;
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(1);
  s.push(2);
  s.push(13);

  // cout<<getMin(s)<<endl;
  // cout<<getMin(s)<<endl;
  // cout<<getMin(s)<<endl;
  // cout<<getMin(s)<<endl;
  // cout<<getMin(s)<<endl;

  sort(s);
  while(!s.empty()){
    cout<<s.top()<<" ";//>>>>
    s.pop();
  }


  return 0;
}