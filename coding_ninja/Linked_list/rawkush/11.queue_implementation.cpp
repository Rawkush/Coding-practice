#include<iostream>
using namespace std;
template<typename T>
class Node{
  public:
  T data;
  Node<T> *next;
  Node(T data){
    next=NULL;
    this->data=data;
  }
};

template<typename T>
class Queue{
  Node <T> *front; //head
  Node <T> *tail;
  public:
  Queue(){
    front=NULL;
    tail=NULL;
  }
  void enqueue(T data){
    Node <T> *newNode = new Node<T>(data);
    if(front==NULL){
      front=newNode;
      tail=newNode;
    }else{
      tail->next=newNode;
      tail=newNode;
    }
  }
  T deQueue(){
    T deQueueData = front->data;
    front= front->next;
    return deQueueData;
  }
    void print()
    {
        Node<T> *head= front;
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
    }
};
int main(){
  Queue <int> queue;
  queue.enqueue(12);
  queue.enqueue(14);
  queue.print();
  return 0;
}