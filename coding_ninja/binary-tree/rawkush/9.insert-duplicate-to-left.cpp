void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root==NULL) return;
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    BinaryTreeNode<int> *left = root->left;
    root->left = new BinaryTreeNode<int>(root->data);
    root->left->left = left;
}