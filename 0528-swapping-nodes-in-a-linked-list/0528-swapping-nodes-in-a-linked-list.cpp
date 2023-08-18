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
  ListNode* swapNodes(ListNode* head, int k) {
    if(!head || !head->next) return head;

    ListNode* tmpHead = new ListNode(-1);
    tmpHead->next =head;
    
    ListNode *curr = tmpHead; 

    ListNode *itr1 = tmpHead;
    ListNode *itr2 = tmpHead;
    for(int i=0; i<k; i++){
      itr1 = curr;
      curr= curr->next;
    }
    while(curr && curr->next){
      itr2= itr2->next;
      curr= curr->next;
    }
    //both are pointing to same element then no need to swap anything
    if(itr1==itr2) return head;

    // if swapping adjacent nodes
    if(itr1->next==itr2){

      itr1->next = itr2->next;
      itr2->next = itr2->next->next;
      itr1->next->next =itr2;
      return  tmpHead->next;
    }
    //swapping if adjacent
    if(itr2->next==itr1){
      itr2->next = itr1->next;
      itr1->next = itr1->next->next;
      itr2->next->next =itr1;
      return  tmpHead->next;
    }
    
    ListNode *node1 = itr1->next;
    ListNode *node2 = itr2->next;
    ListNode *node1n = node1->next;
    ListNode *node2n = node2->next;

    itr2->next = node1;
    itr1->next = node2;
    node2->next = node1n;
    node1->next = node2n;
 
    return tmpHead->next;
  }
};