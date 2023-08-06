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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry =0;
      ListNode* head= NULL;
      ListNode* tail = NULL;
      while(l1!=NULL && l2!=NULL) {
        int sum = l1->val +l2->val + carry;
        carry = sum/10;
        sum = sum > 9 ? sum%10 : sum;
        if(head==NULL){
          head = new ListNode(sum);
          tail = head;
        }else{
          tail->next = new ListNode(sum);
          tail= tail->next;
        }
        l1=l1->next;
        l2= l2->next;
      }
      while(l1!=NULL){
        int sum = l1->val + carry;
        carry = sum/10;
        sum = sum > 9 ? sum%10 : sum;
        tail->next = new ListNode(sum);
        tail= tail->next;
        l1 = l1->next;
      }
      while(l2!=NULL){
        int sum = l2->val + carry;
        carry = sum/10;
        sum = sum > 9 ? sum%10 : sum;
        tail->next = new ListNode(sum);
        tail= tail->next;
        l2 = l2->next;
      }
      if(carry>0){
        tail->next = new ListNode(carry);
        carry = 0 ;
        tail = tail->next;
      }
      return head;
    }
};