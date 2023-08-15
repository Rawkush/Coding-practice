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
    ListNode* partition(ListNode* head, int x) {
      ListNode* head1 = NULL;
      ListNode* head2 = NULL;
      ListNode* tail1= NULL;
      ListNode* tail2 =NULL;

      ListNode* ptr= head;
      while(ptr){
        if(ptr->val<x){
          if(!head1){
            head1 = ptr;
            tail1= ptr;
          }else tail1->next= ptr;
          tail1= ptr;
        }else{
          if(!head2){
            head2 = ptr;
            tail2= ptr;
          }else tail2->next = ptr;
          tail2=ptr;
        }
        ptr=ptr->next;
      }
      if(tail2) tail2->next =NULL;
      if(tail1) tail1->next =NULL;
      if(!head1) return head2;
      tail1->next =head2;
      return head1;
    }
};