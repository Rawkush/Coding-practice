#include<bits/stdc++.h>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int val) : val(val), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode *head=NULL;
  ListNode *tail=NULL;
  int carry = 0;
  while(l1!=NULL || l2!=NULL || carry!=0) {
    int sum = carry;
    if(l1!=NULL){
      sum = sum + l1->val;
      l1 = l1->next;
    }
    if(l2!=NULL){
      sum = sum + l2->val;
      l2 = l2->next;
    }
    carry = sum/10;
    sum =sum %10;
    if(head ==NULL){
      head = new ListNode(sum);
      tail=head;
    }
    else{
      tail->next= new ListNode(sum);
      tail = tail->next;
    }
  }
  return head;
}

int main(){

  return 0;
}