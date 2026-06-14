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
    ListNode *reverse(ListNode*head) {
        ListNode *prev = NULL;
        while(head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next =NULL;
        head2 = reverse(head2);
        int sum=0;
        
        while(head && head2) {
            sum = max(sum, head->val + head2->val);
            cout<<head->val<<" "<<head2->val<<" "<<sum;
            head=head->next;
            head2=head2->next;
        }
        return sum;
    }
};