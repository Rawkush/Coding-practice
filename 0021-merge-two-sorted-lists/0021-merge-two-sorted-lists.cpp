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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head =NULL;
    ListNode* tail = NULL;
    if(list1 ==NULL && list2 ==NULL) return NULL;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;


    int i=0;
    while(list1!=NULL && list2!=NULL){
      if(list2->val < list1->val){
        if(head==NULL){ 
          head = list2;
          tail = head;
        }else{
          tail->next = list2;
          tail= tail->next;
        }
        list2 = list2->next;
      }else{
        if(head==NULL) {
          head= list1;
          tail = head;
        }
        else{
          tail->next = list1;
          tail= tail->next;
        } 
        list1 = list1->next;
      }
    }
    if(list1 ==NULL){
      tail->next = list2;
      tail = tail->next;        
    }
    if(list2 ==NULL){
      tail->next = list1;
      tail = tail->next;        
    }
    return head;
  }
};