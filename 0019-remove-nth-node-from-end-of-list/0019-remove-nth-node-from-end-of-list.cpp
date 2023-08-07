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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *fast = head;
      ListNode *slow =head;
      if(n==1 && head->next==NULL) return NULL;
      while(n>0 && fast->next!=NULL){
        fast = fast->next;
        n--;
      }

      // this means first element needs to be removed
      if(fast->next==NULL && n>0){
        slow= slow->next;
        head->next = NULL;
        delete head;
        return slow;
      }

      while(fast->next!=NULL){
        fast = fast->next;
        slow =  slow->next;
      }

      slow->next = slow->next->next;
      return head;

    }
};