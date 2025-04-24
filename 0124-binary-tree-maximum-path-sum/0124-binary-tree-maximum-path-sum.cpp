
class Solution {
public:

    int helper(TreeNode*root, int &m){
        if(!root) return 0;
        int l = max(helper(root->left,m), 0);
        int r = max(helper(root->right,m), 0);
        /** 
        * adding tho negative number will always make sum less, so if whole bottom nodes
        * are negative do not include them in path sum, is a node is -ve in between 
        * but when calculating the sum overtall sum is not 0nve then it can be included
        * but if -ve then do not need to include the whole bottom subtree
         */
        m = max(m, l+r+root->val);
        return  max(l,r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int m=INT_MIN;
        helper(root, m);
        return m;
    }
};