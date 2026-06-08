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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = NULL;
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> isChild;

        for(auto x:descriptions) {
            TreeNode *p = NULL;
            TreeNode *c = NULL;
            if(mp.count(x[1])>0) c = mp[x[1]];
            else {
                c = new TreeNode(x[1]);
                mp[x[1]] = c;
            }
            
            if(mp.count(x[0])>0) p = mp[x[0]];
            else {
                p = new TreeNode(x[0]);
                mp[x[0]] = p;
            }

            if(x[2]==1) p->left = c;
            else p->right = c;
            
            isChild[x[1]] = true;
        }

        for(auto x: descriptions) {
            if(isChild.count(x[0])<=0) {
                // cout<<x[0];
                return mp[x[0]];
            }
        }

        return NULL;
    }
};