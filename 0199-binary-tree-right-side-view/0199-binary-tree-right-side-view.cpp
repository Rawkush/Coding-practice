/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> res;
      queue<TreeNode*> q;
      if(root)  q.push(root);
      while(!q.empty()){
        int size = q.size();
        int lastItem = -1;
        for(int i=0; i<size; i++){
          TreeNode* it= q.front();
          q.pop();
          if(it->left) q.push(it->left);
          if(it->right) q.push(it->right);
          lastItem = it->val;
        }
        res.push_back(lastItem);
      }
      return res;
    }
};