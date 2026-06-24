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
    int countNodes(TreeNode* root) {
        int lh = 0, rh=0;
        TreeNode *tmp = root;
        while(tmp) {
            tmp=tmp->left;
            lh++;
        }
        tmp =root;
        while(tmp) {
            tmp=tmp->right;
            rh++;
        }

        if(lh == rh) return (1<<lh)-1; // 2^n -1
        lh = countNodes(root->left);
        rh = countNodes(root->right);
        return lh+rh+1;
    }
};