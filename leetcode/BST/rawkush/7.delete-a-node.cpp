TreeNode *getRightMin(TreeNode *root)
{
  if (root->left == NULL )return root;
  return getRightMin(root->left);
}

TreeNode *deleteNode(TreeNode *root, int key)
{
  if (root == NULL)
    return NULL;
  if (root->val > key)
  {
    root->left = deleteNode(root->left, key);
  }
  if (root->val < key)
  {
    root->right = deleteNode(root->right, key);
  }
  if (root->val == key)
  {
    if(root->left==NULL && root->right == NULL) return NULL;
    if(root->left == NULL && root->right!=NULL) return root->right;
    if(root->right == NULL && root->left!=NULL) return root->left;
    //if both exists
    TreeNode *min = getRightMin(root->right);
    TreeNode* newNode =new TreeNode(min->val);
    newNode->right=deleteNode(root->right, newNode->val);
    newNode->left= root->left;
    return newNode;
  }
  return root;
}