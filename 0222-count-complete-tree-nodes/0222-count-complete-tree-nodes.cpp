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
        if(!root) return 0;
        int lh=0;
        int rh=0;
        TreeNode*node=root;
        while(node){
            node=node->left;
            lh++;
        }
        node=root;
        while(node){
            node=node->right;
            rh++;
        }
        if(lh==rh){
            return pow(2, lh)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};