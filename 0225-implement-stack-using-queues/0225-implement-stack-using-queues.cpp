#include<queue>
class MyStack {
public:   
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int qsize=q.size();
        q.push(x);
        for(int i=0; i<qsize; i++){
            int tmp =  q.front();
            q.pop();
            q.push(tmp);
        }
    }
    
    int pop() {
        int data = q.front();
        q.pop();
        return data;
    }
    
    int top() {
        return q.front();
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