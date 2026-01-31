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
    pair<int, TreeNode*> helper(TreeNode* root, int d){
        if(root==NULL) return {d , NULL};
        pair<int, TreeNode*> p1 = helper(root->left, d+1);
        pair<int, TreeNode*> p2 = helper(root->right, d+1);
        int d1 = p1.first;
        int d2 = p2.first;
        if(d1==d2) return {d1,root};
        else if(d1 > d2) return {d1, p1.second};
        return {d2, p2.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<int, TreeNode*> p = helper(root, 0);
        return p.second;
    }
};