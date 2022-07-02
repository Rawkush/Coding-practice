


    bool isValidBST(TreeNode* root) {
      if(root==NULL) return true;
      if(root->left!=NULL && root->left->data>root->data) return false;
      if(root->right!=NULL && root->right->data>root->data) return false;
      return isValidBST(root->right) && isValidBST(root->left);
    }