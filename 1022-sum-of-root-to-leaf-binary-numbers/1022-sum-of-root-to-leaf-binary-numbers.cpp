/**
*. 11001
       
    2^4 *1 + 2^3*1 +   2^0 * 1

    sum 
 */

class Solution {
public:
    int helper(TreeNode* root, int sum ) {
        if(root==NULL) return 0;
        sum = sum*2 + root->val; // we are adding last element so its 2^0 
        if(!root->left && !root->right) return sum;
        return helper(root->left, sum) + helper(root->right, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};