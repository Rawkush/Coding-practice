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

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next == NULL) return head; //NULL or one item

        //if starting items are deplicate keep rmoveing them
        ListNode *tmpHead = head->next;
        //Delete head
        while(tmpHead && tmpHead->val == head->val) {
            tmpHead = tmpHead->next;
            if(tmpHead == NULL) return NULL; // all same items

            if(tmpHead->val != head->val) {
                //now we have a node this we need so 
                head = tmpHead;
                tmpHead = tmpHead->next;
            }
        }
        // after this all duplicate items from head should be removed
        ListNode *prev = head;
        ListNode *curr = head->next;
        while(curr) {
            bool isDuplicate = false;
            while(curr->next && curr->next->val == curr->val) {
                curr=curr->next;
                isDuplicate =true;
            }
            if(isDuplicate) {
                prev->next = curr->next;
            } else prev = prev->next;
            curr = curr->next;
        }
        // prev->next = curr;
        return head;
    }
};