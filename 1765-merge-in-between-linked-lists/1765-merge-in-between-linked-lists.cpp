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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      if(!list1) return list2;
      if(list1 && !list1->next) return list2;

      ListNode* ptr =list1;
      ListNode* tail1=NULL;
      ListNode* tail2=NULL;
      // int prev = -1;
      int idx=0;
      while(ptr && ptr->next){
        if(idx+1==a){
          tail1=ptr;
        }
        else
        if(idx==b){
          tail2=ptr->next;
          break;
        }
        ptr= ptr->next;
        idx++;
      }
      cout<< tail1->val;
      tail1->next = list2;
      while(list2 && list2->next){
        list2 = list2->next;
      }
      list2->next=tail2;
      return list1;
    }
};