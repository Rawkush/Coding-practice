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
    void helper(TreeNode* root,int rsum, int &tsum) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            tsum+=rsum*10 + root->val;
            return;
        }
        int newSum = rsum*10 + root->val;
        helper(root->left, newSum, tsum );
        helper(root->right, newSum, tsum );
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int rootSum =0;
        helper(root, rootSum, sum);
        return sum;
    }
};