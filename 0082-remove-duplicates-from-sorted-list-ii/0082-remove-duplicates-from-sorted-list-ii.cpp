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
  void print(ListNode* head){
    while(head){
      cout<<head->val<<" ";
      head=head->next;
    }
    cout<<endl;
  }
  ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* newHead = NULL;
    ListNode* tail = NULL;
    int prev= -111;
    while(head && head->next){
     if(prev ==-111 && head->val ==head->next->val){
       prev = head->val;
       continue;
     }
     ListNode *next = head->next;
      // cout<<prev<<" : "<<head->val<<" : "<<head->next->val<<endl;
      if(head->val!=prev && head->val!=next->val){
        if(!newHead){
          newHead = head;
          tail =  head;
        }else{
           tail->next = head;
           tail= tail->next;
        }
        // prev = head->val;
        head->next=NULL;
        // print(newHead);
        // cout<<head->val<<" ";
      }
      prev = head->val;
      head= next;
    }  
    if( head && head->val!=prev){
      if(!newHead){
        newHead = head;
        tail= head;
      }else   tail->next = head;
    }
    
    return newHead;
  }
};