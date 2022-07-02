


TreeNode* removeLeafNodes(TreeNode* root, int target) {
  if(root == NULL) return NULL;
  TreeNode* left = removeLeafNodes(root->left, target);
  TreeNode* right = removeLeafNodes(root->right, target);
  root->left=left;
  root->right=right;
  if(root->left == NULL && root->right == NULL && root->data==target) return NULL;

  return root;
}