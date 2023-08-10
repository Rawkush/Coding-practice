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

/**
* iterative
*/

  pair<ListNode*, ListNode*> reverseList(ListNode* head) {
    ListNode* prev=NULL;
    ListNode* newtail = head;
    while(head){
      ListNode* curr = head;
      head= head->next;
      curr->next = prev;
      prev= curr;
    }
    return make_pair(prev, newtail );
  }


  ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* newHead = NULL;
    ListNode* curr = head;
    ListNode* tail =head;
    ListNode* prev = NULL;
    int i = 1;
    while(tail!=NULL && tail->next!=NULL && i<k){
      tail=tail->next;
      i++;

      if(i==k){
        ListNode* next = tail->next;
        tail->next =NULL;
        pair<ListNode*, ListNode*> rl =  reverseList(curr);
        if(newHead==NULL){
          newHead = rl.first;
        }else{
          prev->next = rl.first;
        }
       
        prev = rl.second;
        rl.second->next = next;
        tail= next;
        curr=next;
        i=1;
      }
    }
    if(newHead) return newHead;
    return head;
  }





/**
*  Recursive
*/



  // pair<ListNode*, ListNode*> reverseList(ListNode* head) {
  //   ListNode* prev=NULL;
  //   ListNode* newtail = head;
  //   while(head){
  //     ListNode* curr = head;
  //     head= head->next;
  //     curr->next = prev;
  //     prev= curr;
  //   }
  //   return make_pair(prev, newtail );
  // }

  // void print(ListNode*head, ListNode*tail){
  //   while(head!=tail && head!=NULL){
  //     cout<<head->val<<" ";
  //     head=head->next;
  //   }
  // }

  // ListNode* reverseKGroup(ListNode* head, int k) {
  //   if(head==NULL || head->next==NULL) return head;

  //   ListNode* tail= head;
  //   ListNode* newHead = head;


  //   int i = 1;
  //   while(tail!=NULL && tail->next!=NULL && i<k){
  //     tail=tail->next;
  //     i++;
  //   }
  
  //   if(i<k) return head;
  //   ListNode* rt = reverseKGroup(tail->next,k); //right part head
  //   tail->next =NULL;
  //   pair<ListNode*, ListNode*> reversed = reverseList(head);
  //   newHead = reversed.first;
  //   reversed.second->next = rt;
  //   return newHead;
  // }




























};