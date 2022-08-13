#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode* midNode(ListNode *head) {
//   if(head == NULL||head->next == NULL) return head;
//   ListNode *fast = head;
//   ListNode *prev=NULL;
//   ListNode *next=head->next;
//   while(fast!=NULL && fast->next!=NULL){
//     fast= fast->next->next;

//     head->next=prev;
//     prev=head;
//     head=next;
//     next=next->next;
//   }
//   //head->next=prev;
//   return head;
// }

// ListNode* reverse(ListNode *head){
//   if(head->next==NULL || head==NULL) return head;
//   ListNode *prev=NULL;
//   ListNode *next=head->next;

//   while(next != NULL){
//     head->next=prev;
//     prev=head;
//     head=next;
//     next=next->next;
//   }
//   head->next=prev;
//   return head;
// }


/** Find the mid of the list, and reverse the first half od the list,
 now simply compare the two list*/
bool isPalindrome(ListNode* head) {
  if(head==NULL || head->next==NULL) return true;
  ListNode *fast = head;
  ListNode *prev=NULL;
  ListNode *next=head->next;
  while(fast!=NULL && fast->next!=NULL){
    fast= fast->next->next;
    head->next=prev;
    prev=head;
    head=next;
    next=next->next;
  }

  /**  if odd number of elements do not include mid element in 2nd half
    as it is not present in first half
  */
   if(fast!=NULL){
        head=head->next;
   }

   while(head!=NULL && prev!=NULL){
    if(head->val!=prev->val)
      return false;
    prev = prev->next;
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
