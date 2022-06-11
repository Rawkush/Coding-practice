#include<queue>
class MyStack {
public:

    queue<int> q;
    queue<int> tmp;
    MyStack() {

    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        while(q.size()>1){
            tmp.push(q.front());
            q.pop();
        }

        int front = q.front();
        q.pop();
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        return front;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */