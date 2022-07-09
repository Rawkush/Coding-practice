int updateTree(Node *root){
  if(root==NULL) return 0;
  int sum=root->data;
  int rightSum = updateTree(root->right);
  root->data += rightSum;
  int leftSum = updateTree(root->left);
  if(root->left){
    root->left->data = leftSum + rightSum + root->data;
  }
  return sun + rightSum + leftSum;
}
Node *modify(Node *root)
{
  // Your code here
  if (root == NULL)
    return NULL;
  updateTree(root);
  return root;
}