  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root==NULL) return NULL;

      TreeNode* left = NULL;
      TreeNode* right = NULL;
      if(root->val >= q->val || root->val >= p->val )
        left =  lowestCommonAncestor(root->left, p, q);
      if(root->val <= q->val || root->val <= p->val )
        right = lowestCommonAncestor(root->right, p, q);
      if(root->val == q->val || root->val ==p->val) return root;

      if(right!=NULL && left!=NULL) return root;
      if(left) return left;
      if(right) return right;
      return NULL;
   }