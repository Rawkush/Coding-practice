#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *first=NULL;
bool isPalindrome(ListNode* head) {
  first=head;
  return checkPalindrome(head);
}

bool checkPalindrome(ListNode* head){
 if(head==NULL) return true;
  bool check = checkPalindrome(head->next);
  if(first->val!=head->val){
    return false;
  }
  first=first->next;
  return check;
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
