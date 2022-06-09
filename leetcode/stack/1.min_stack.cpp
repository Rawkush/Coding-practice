#include<stack>
#include<iostream>
using namespace std;
class MinStack {
public:
    stack<int> s;
    stack<int> smin;
    MinStack() {
    }

    void push(int val) {
        if(s.empty()){
            s.push(val);
            smin.push(val);
            return;
        }


        if(smin.top()>=val){
            smin.push(val);
        }
        s.push(val);
    }

    void pop() {
        if(s.top()==smin.top()){
            smin.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main(){

   MinStack min;
   min.push(9);
   min.push(5);
   min.push(10);
   min.push(20);
   min.push(3);
   cout<<min.getMin()<<endl;
   min.pop();
   cout<<min.getMin()<<endl;
   min.pop();
    cout<<min.getMin()<<endl;
    min.pop();
  cout<<min.getMin()<<endl;
   min.pop();
  cout<<min.getMin()<<endl;
   min.pop();



   return 0;
 }