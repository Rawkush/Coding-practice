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
  bool isEven(int num){
    return num%2==0;
  }
  ListNode* oddEvenList(ListNode* head) {
    if(head==NULL) return NULL;
    ListNode *ohead = NULL;
    ListNode *otail = NULL;
    ListNode *ehead = NULL;
    ListNode *etail =NULL;
    ListNode *next = head->next;

    ohead= head;
    otail = head;
    head= next;
    int count = 2;
    while(head!=NULL){
      ListNode *next = head->next;
      head->next = NULL;
      if(isEven(count)){
        if(ehead==NULL){
          ehead = head;
          etail = head;
        }else{
          etail->next = head;
          etail = head;
        }
      }else{
        if(ohead==NULL){
          ohead= head;
          otail = head;
        }else{
          otail->next=head;
          otail = head;
        }
      }
      count++;
      head=next;
    }

    if(ehead==NULL) return ohead;
    if(ohead==NULL) return ehead;
    
    otail->next=ehead;
    return ohead;
  }
};