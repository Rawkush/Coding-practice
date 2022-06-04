#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data=data;
        next=NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *top;
    int size;
public:
    Stack()
    {
        size=0;
        top=NULL;
    }
    void push(T data)
    {
        Node<T> *newNode=  new Node<T>(data);
        newNode->next=this->top;
        top=newNode;
    }
    T pop()
    {
        T popData=top->data;
        top=top->next;
        return popData;
    }
    void print()
    {
        Node<T> *head= top;
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
    }
};

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.print();
    return 0;
}
