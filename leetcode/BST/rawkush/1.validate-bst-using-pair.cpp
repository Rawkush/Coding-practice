#include "0.tree.h"
using namespace std;

class Pair
{
public:
  int max;
  int min;
  bool valid;
  Pair(int max, int min)
  {
    this->max = max;
    this->min = min;
    valid = true;
  }
  Pair(int max, int min, bool valid)
  {
    this->max = max;
    this->min = min;
    this->valid = valid;
  }
};

Pair *checkValid(TreeNode *root)
{
  if (root->left == NULL && root->right == NULL)
  {
    return new Pair(root->val, root->val);
  }
  bool valid = true;
  int maxv=root->val;
  int minv=root->val;
  if (root->left)
  {
    Pair *left = checkValid(root->left);
    maxv=max(root->val,left->max);
    minv=min(root->val, left->min);
    valid = valid && left->valid && root->val > left->max;
  }
  if (root->right)
  {
    Pair *right = checkValid(root->right);
    maxv=max(maxv,right->max);
    minv=min(minv, right->min);
    valid = valid && right->valid && root->val < right->min;
  }
  return new Pair(maxv, minv, valid);
}

    bool isValidBST(TreeNode* root) {
     if(root==NULL) return true;
      return checkValid(root)->valid;
    }

bool isValidBST(TreeNode *root)
{
  if (root == NULL)
    return true;
  return checkValid(root)->valid;
}

int main()
{
  BinaryTreeNode<int> *root = takeInputLevelWise();
  printLevelWise(root);
  return 0;
}