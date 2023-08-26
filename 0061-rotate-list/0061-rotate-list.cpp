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
#define debug(x) cout<<#x<<" "<<x<<endl;
#define debugL(x) cout<<#x<<" "<<x->val<<endl;
class Solution {
public:

  ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    ListNode *itr1 = head;
    int len =1;
    while(itr1 && itr1->next){
      itr1 = itr1->next;
      len++;
    }
    int r = k%len;
    if(r == len) return head; 
    itr1->next = head;
    itr1= head;
    for(int i=1; i < len-r; i++){
      itr1 = itr1->next; 
    } 

    head = itr1->next;
    itr1->next =NULL;
    return head;
  }
};