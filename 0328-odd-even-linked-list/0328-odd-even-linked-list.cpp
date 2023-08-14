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
  // bool isEven(int num){
  //   return num%2==0;
  // }
  // ListNode* oddEvenList(ListNode* head) {
  //   if(head==NULL) return NULL;
  //   ListNode *ohead = head;
  //   ListNode *otail = head;
  //   ListNode *ehead = NULL;
  //   ListNode *etail =NULL;
  //   head= head->next;
  //   int count = 2;
  //   while(head!=NULL){
  //     ListNode *next = head->next;
  //     head->next = NULL;
  //     if(isEven(count)){
  //       if(ehead==NULL){
  //         ehead = head;
  //         etail = head;
  //       }else{
  //         etail->next = head;
  //         etail = head;
  //       }
  //     }else{
  //       otail->next=head;
  //       otail = head;
  //     }
  //     count++;
  //     head=next;
  //   }
  //   otail->next=ehead;
  //   return ohead;
  // }

// 2nd solution
  // ListNode* oddEvenList(ListNode* head) {
  //   if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
  //   ListNode *otail = head;
  //   ListNode *ehead = head->next;
  //   ListNode *etail = head->next;
  //   while(otail->next && etail->next){
  //     //odd->next is even 
  //     // even->next is odd
  //     otail->next=etail->next;
  //     otail= otail->next;
  //     etail->next= otail->next;
  //     etail = etail->next;
  //   }
  //   otail->next= ehead;
  //   return head;
  // }

  ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* ohead=head;
    ListNode* otail =head;
    ListNode* ehead = head->next;
    ListNode* etail = head->next;
    while(otail->next && etail->next){
      otail->next = otail->next->next;
      etail->next = etail->next->next;
      etail= etail->next;
      otail= otail->next;
    }
    otail->next = ehead;
    return ohead;
  }


};