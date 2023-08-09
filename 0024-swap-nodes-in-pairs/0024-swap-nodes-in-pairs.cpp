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


  ListNode* swapPairs(ListNode* head) {
    if(head==NULL || head->next ==NULL ) return head;

    ListNode* prev = NULL;
    ListNode* curr =head;
    ListNode* newHead= NULL;
    while(curr!=NULL && curr->next!=NULL){
      cout<< curr->val<< " ";

      ListNode* next = curr->next;
      // swap curr with next;
      if(prev==NULL){
        head= next;
        newHead= next;
      }else{
        prev->next= next;
      }
      curr->next = next->next;
      next->next = curr;
      prev= curr;
      curr= curr->next;
    }
    return head;
  }
};












