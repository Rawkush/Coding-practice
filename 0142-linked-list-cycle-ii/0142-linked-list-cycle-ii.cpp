/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if(!head) return head;
    ListNode* tail =NULL;;
    ListNode* head2= NULL;
    ListNode* slow = head;
    ListNode* fast = head->next;
    bool isCyclePresent =false;
    while(fast && fast->next){
      if(fast==slow){
        tail=fast;
        // cout<<"tail "<<fast->val;
        head2= fast->next;
        fast->next = NULL;
        isCyclePresent=true;
        break;
      }
      fast = fast->next->next;
      slow = slow->next;
    }
    if(!isCyclePresent) return NULL;

    int len1 =0;
    int len2=0;

    ListNode* ptr1= head;
    ListNode* ptr2= head2;
    while(ptr1){
      len1++;
      ptr1= ptr1->next;
    }
    while(ptr2){
      len2++;
      ptr2= ptr2->next;
    }
    // cout<<"\n len1 "<<len1<<" len2 "<<len2<<endl;
    ptr1 = head;
    ptr2 = head2;
    // if(len1==len2) return head;
  // cout<<"tetspoint<<\n";
    int diff = abs(len1-len2);
    // cout<<"dif "<<diff<<endl;
    while(diff){
      diff--;
      if(len1>len2){
        ptr1=ptr1->next;
      }else{
        ptr2=ptr2->next;
      }
    }
  // cout<<"ptr1 "<<ptr1->val<<endl<<"ptr1 "<<ptr2->val<<endl;

    while(ptr1 && ptr2){
      if(ptr1==ptr2) {
        //undo breaking of list
        // cout<<"\n pos "<<ptr1->val;
        tail->next = head2;
        //return node;
        return ptr1;
      }
      ptr1=ptr1->next;
      ptr2=ptr2->next;
    }
    return head;
  }
};