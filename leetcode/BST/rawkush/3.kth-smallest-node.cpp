int kth(TreeNode *root, int &k){
    if(root->left==NULL && root->right==NULL){
      k--;
      return root->val;
    }
    int sm = root->val;
    if(root->left){
       sm = kth(root->left,k);
    }
    if(k<=0) return sm;
    if(k--==1) return root->val;
    if(root->right){
      sm = kth(root->right,k);
      return sm;
    }
    return root->val;
 }

  int kthSmallest(TreeNode* root, int k) {
      return kth(root, k);
  }