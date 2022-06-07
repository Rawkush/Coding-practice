#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* midNode(ListNode *head) {
  ListNode *fast = head;
  while(fast!=NULL && fast->next!=NULL){
    fast= fast->next->next;
    head=head->next;
  }
  return head;
}

ListNode* reverse(ListNode *head){
  /** recursive approach to reverse */
  // if(head->next==NULL || head==NULL) return head;
  // ListNode* newHead= reverse(head->next);
  // ListNode * tail = head->next;
  // tail->next=head;
  // head->next=NULL;
  // return newHead;

  if(head->next==NULL || head==NULL) return head;
  ListNode *prev=NULL;
  ListNode *next=head->next;

  while(next != NULL){
    head->next=prev;
    prev=head;
    head=next;
    next=next->next;
  }
  head->next=prev;
  return head;
}

bool isPalindrome(ListNode* head) {
  if(head==NULL || head->next==NULL) return true;
  ListNode* mid =midNode(head);
  ListNode* head2 = reverse(mid);
  while(head!=mid && head2!=NULL){
    if(head->val!=head2->val)
      return false;
    head2 = head2->next;
    head = head->next;
  }
  return true;
}

int main(){
  ListNode n(1);
  ListNode n2(2);
  n.next = &n2;
  ListNode n3(3);
  n2.next=&n3;
  ListNode n4(2);
  n3.next= &n4;
  ListNode n5(1);
  n4.next=&n5;
  cout<< isPalindrome(&n);
  return 0;
}
