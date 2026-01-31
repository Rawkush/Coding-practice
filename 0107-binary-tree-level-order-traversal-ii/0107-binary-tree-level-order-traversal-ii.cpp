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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>>res;
        if(!root) return res;
        while(!q.empty()) {
            int s = q.size();
            vector<int> lvl;
            for(int i=0; i<s; i++) {
                TreeNode *n = q.front();
                q.pop();
                lvl.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            res.push_back(lvl);
        }
        reverse(res.begin(), res.end());
        return res; 
    }
};