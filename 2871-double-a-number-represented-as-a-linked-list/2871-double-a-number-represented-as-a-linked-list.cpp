/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* reverse(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* prev =NULL;
    while(head){
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head= next;
    }
    return prev;
  }
  ListNode* doubleIt(ListNode* head) {
    ListNode *newHead = reverse(head);
    int carry = 0;
    ListNode *ptr = newHead;
    ListNode *last = NULL;
    while(ptr){
      int val = ptr->val *2 + carry;
      carry = val/10;
      val = val%10;
      ptr->val = val;
      last= ptr;
      ptr= ptr->next;
    }  
    if(carry){
      ListNode * newNode = new ListNode(carry);
      last->next = newNode;
    }  
    return reverse(newHead);
  }

};