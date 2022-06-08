#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  if(head ==NULL  || head->next == NULL) return false;

  ListNode *slow=head;
  ListNode *fast=head->next;
  while(fast!=NULL&& fast->next != NULL){
    if(slow==fast) return true;
    slow=slow->next;
    fast=fast->next->next;
  }
  return false;
}

int main(){

  Node* node = new Node(1);
  Node*head= node;

  node->next=new Node(2);
  node=node->next;

  node->next=new Node(3);
  node=node->next;

  node->next=new Node(4);
  node=node->next;

  node->next=new Node(5);
  node=node->next;

  cout<< hasCycle(head)<<endl;//>>
}