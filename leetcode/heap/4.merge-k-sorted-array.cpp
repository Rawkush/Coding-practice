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
//  bool operator<(const ListNode* p1, const ListNode* p2)
// {
//     return p1->val > p2->val;
// }

#define debug(x) cout<<#x<<" "<<x<<endl;
#define debugL(x) cout<<#x<<" "<<x->val<<endl;

    class Compare
    {
    public:
        bool operator() (ListNode* l1, ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.size()==0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(int i=0; i<lists.size(); i++){
          if(lists[i]==NULL) continue;
          pq.push(lists[i]);
        }
        if(pq.empty()) return NULL;
        ListNode*head=pq.top();
        ListNode*tail=pq.top();
        pq.pop();
        if(tail!=NULL && tail->next!=NULL){
          pq.push(tail->next);
          tail->next=NULL;
        }
        while(!pq.empty()){
          ListNode *smallNode = pq.top();
          pq.pop();
          if(smallNode==NULL) continue;
          tail->next=smallNode;
          tail=tail->next;
          if(smallNode->next!=NULL){
            pq.push(smallNode->next);
            smallNode->next=NULL;
          }
        }
        return head;
    }
};