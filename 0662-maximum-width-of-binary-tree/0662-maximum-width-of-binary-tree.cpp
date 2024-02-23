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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long>> q;
        q.push({root, 0});
        int mw = 0; //mx width
        while(!q.empty()){
            int n = q.size();
            int cw=0; //current width
            long parentIdx = q.front().second; //left most itemIDx in parent
            int firstIdx =0;
            int lastIdx = 0;

            for(int i=0; i<n; i++){
                pair<TreeNode*, long> p = q.front();
                q.pop();
                TreeNode* node= p.first;
                long idx = p.second - parentIdx; // subtracting this so that
                // for every lvl idx starts from 0 
                if(i==0){
                    firstIdx = idx;
                }
                lastIdx = idx;
                if(node->left){
                    q.push({node->left, 2*idx+1});
                }
                if(node->right){
                    q.push({node->right,  2*idx+2});
                }
            }
            cw=lastIdx - firstIdx +1;
            mw = max(mw, cw);
        }

        return mw;
    }
};