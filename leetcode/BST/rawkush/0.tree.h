// template
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};
void printTree(BinaryTreeNode<int> *root)
{
  if (root == NULL)
    return;
  cout << root->data << ":";
  if (root->left)
    cout << " L " << root->left->data << ",";
  if (root->right)
    cout << " R " << root->right->data;
  cout << endl;
  printTree(root->left);
  printTree(root->right);
}
void printLevelWise(BinaryTreeNode<int> *root)
{
  // Write your code here
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty())
  {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << front->data << ":";
    if (front->left)
    {
      cout << "L:" << front->left->data;
      pendingNodes.push(front->left);
    }
    else
      cout << "L:" << -1;
    cout << ",";
    if (front->right)
    {
      pendingNodes.push(front->right);
      cout << "R:" << front->right->data;
    }
    else
      cout << "R:" << -1;
    cout << endl;
  }
}

BinaryTreeNode<int> *takeInputLevelWise()
{
  int rootData;
  cout << "Enter root Data: ";
  cin >> rootData;
  if (rootData == -1)
    return NULL;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty())
  {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter left child of " << front->data << endl;
    int leftChildData;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }
    cout << "Enter right child of " << front->data << endl;
    int rightChildData;
    cin >> rightChildData;
    if (rightChildData != -1)
    {
      BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
      front->right = child;
      pendingNodes.push(child);
    }
  }
  return root;
}
