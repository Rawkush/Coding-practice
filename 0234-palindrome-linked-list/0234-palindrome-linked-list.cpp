/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
bool isPalindrome(ListNode* head) {
  if(head==NULL || head->next==NULL) return true;
  ListNode *fast = head;
  ListNode *prev=NULL;
    ListNode *next=head->next;

  //reverse first ha
  while(fast!=NULL && fast->next!=NULL){
    fast= fast->next->next;
    head->next=prev;  // pointing cuurent element to previous
    prev=head;   // updating previous to cureeny elemt
    head=next;  /// moving current element to next  
    next=next->next;
  }
    // this means slow is pointing at eact middle mode,
  // ex 1 3 5 6 7
  // 5 is our middle and for palindrome we do not need to include this mid, if left and ight are equal then 
  // it is

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

};