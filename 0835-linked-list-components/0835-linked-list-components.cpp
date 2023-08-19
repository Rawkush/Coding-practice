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
  int numComponents(ListNode* head, vector<int>& nums) {
    set<int> mySet ;
    for(int i=0; i< nums.size(); i++){
      mySet.insert(nums[i]);
    }
    int count =0;
    int len =0;
    while(head){
      if(mySet.count(head->val)){
        len++;
      }else{
        if(len>0){
          count++;
          len=0;
        }
      }
      head= head->next;
    }
    if(len>0) count++;
    return count;
  }
};