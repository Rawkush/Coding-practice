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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *createBST(vector<int> &nodes, int l, int r){
        if(l>r) return NULL;
        if(l==r) {
            return new TreeNode(nodes[l]);
        }
        int mid = (l+r)/2;
        TreeNode *head = new TreeNode(nodes[mid]);
        TreeNode *left = createBST(nodes, l, mid-1);
        TreeNode *right = createBST(nodes, mid+1, r);
        head->left = left;
        head->right = right;
        return head;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> nodes;
        ListNode *tmp = head;
        while(tmp) {
            nodes.push_back(tmp->val);
            tmp=tmp->next;
        }
        return createBST(nodes, 0, nodes.size()-1);
    }
};