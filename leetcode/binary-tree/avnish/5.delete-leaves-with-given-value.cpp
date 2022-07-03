class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if(root==NULL) return NULL;
        
        
        TreeNode* left=removeLeafNodes(root->left, target);
        TreeNode* right=removeLeafNodes(root->right,target);
        
        if(left==NULL && right==NULL && root->val==target) return NULL;
        
        root->left=left;
        root->right=right;
     
        
        return root;
        
    }
};