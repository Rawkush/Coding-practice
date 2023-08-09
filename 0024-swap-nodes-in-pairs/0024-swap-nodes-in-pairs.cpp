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



  /**
  *  iterative
  */
  // ListNode* swapPairs(ListNode* head) {
  //   if(head==NULL || head->next ==NULL ) return head;
  //   ListNode* prev = NULL;
  //   ListNode* curr =head;
  //   while(curr!=NULL && curr->next!=NULL){
  //     ListNode* next = curr->next;
  //     if(prev==NULL){
  //       head= next;
  //     }else{
  //       prev->next= next;
  //     }
  //     curr->next = next->next;
  //     next->next = curr;
  //     prev= curr;
  //     curr= curr->next;
  //   }
  //   return head;
  // }

// Recusive
  ListNode* swapPairs(ListNode* head) {
    if(head==NULL || head->next ==NULL ) return head;
    ListNode* rhead = swapPairs(head->next->next);
    ListNode* curr = head;
    ListNode* next= curr->next;
    curr->next = rhead;
    next->next = curr;
    return next;
  }

};












