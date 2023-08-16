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
  ListNode* reverseList(ListNode* head){
    ListNode *prev = NULL;
    while(head){
      ListNode* next =head->next;
      head->next =prev;
      prev = head;
      head=next;
    }
    return prev;
  }

  void reorderList(ListNode* head) {
    ListNode* slow= head;
    ListNode* fast = head;
    while(fast && fast->next){
      fast = fast->next->next;
      slow= slow->next;
    }
    ListNode *head2 = slow->next;
    slow->next =NULL;
    head2 = reverseList(head2);

    ListNode* tail1 = slow;
    ListNode* head1= head;
    while(head1 && head2){
      ListNode* next1 = head1->next;
      ListNode* next2 = head2->next;
      head1->next =head2;
      head2->next = next1;
      head1=next1;
      head2=next2;
    }
    // return head;
  }
};