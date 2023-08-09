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

  // ListNode

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

  void print(ListNode*head, ListNode*tail){
    while(head!=tail && head!=NULL){
      cout<<head->val<<" ";
      head=head->next;
    }
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || head->next==NULL) return head;
    ListNode* tail= head;
    ListNode* newHead = head;
    int i = 1;
    while(tail!=NULL && tail->next!=NULL && i<k){
      tail=tail->next;
      i++;
    }
    // cout<<"st "<<head->val<<" t "<<tail->val<<endl;
    // cout<<"i "<<i<<endl;
    if(i<k) return head;
    // if(i==1 && tail)
    ListNode* rt = reverseKGroup(tail->next,k); //right part head
    tail->next =NULL;
    // cout<<endl<<"before ";
    print(head, tail);
    pair<ListNode*, ListNode*> reversed = reverseList(head);
    cout<<endl<<" after ";
    cout<<"\nrev "<<reversed.first->val<<" end "<<reversed.second->val<<endl;
    print(reversed.first, reversed.second);
    newHead = reversed.first;
    reversed.second->next = rt;
    return newHead;
  }
};