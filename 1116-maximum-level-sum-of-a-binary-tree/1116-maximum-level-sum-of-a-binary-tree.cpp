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
  int maxLevelSum(TreeNode* root) {
    if(!root) return -1;
    queue<TreeNode*> q;
    q.push(root);
    int mx = INT_MIN;
    int cl = 0;
    int mcl = 0;
    while(!q.empty()){
      int sum = 0;
      int lvlSize = q.size();
      cl++;
      for(int i=0; i<lvlSize; i++ ){
        TreeNode *f = q.front();
        sum+=f->val;
        q.pop();
        if(f->right) q.push(f->right);
        if(f->left) q.push(f->left);
      }
      cout<<sum<<" ";

      if(sum>mx) mcl = cl;
 
      mx = max(mx, sum);
    }
    return mcl;
  }
};