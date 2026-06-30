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
        queue<pair<TreeNode*,long long>> q;
        q.push({root, 0});
        long long distance = 0;
        while(!q.empty()) {
            int s = q.size();
            long long idx1  = 0;
            for(int i=0; i<s; i++) { 
                auto p = q.front();
                q.pop();
                if(i==0) {
                  distance = max(distance, (long long)1);
                  idx1 = p.second;
                } else {
                    distance = max(distance, abs(idx1 - p.second) + 1);
                }
                if(p.first->left) {
                    q.push({ p.first->left, (long long)2*p.second + 1 - idx1 });
                }
                if(p.first->right) {
                    q.push({  p.first->right, (long long)2*p.second + 2 - idx1 });
                }
            }
        }
        return distance;
    }
};