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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* lastPtr=head;
        ListNode* kthPtr = head;
        int len = 0;
        while(lastPtr!=NULL) {
            len++;
            lastPtr = lastPtr->next;
        }

        int r = k%len; //actual roation of keys needed
        lastPtr = head;
        for(int i=0; i<r; i++) {
            lastPtr = lastPtr->next;
        }
        while(lastPtr->next!=NULL) {
            lastPtr = lastPtr->next;
            kthPtr = kthPtr->next;
        }

        lastPtr->next = head;
        head = kthPtr->next;
        kthPtr->next=NULL;

        return head;
    }
};