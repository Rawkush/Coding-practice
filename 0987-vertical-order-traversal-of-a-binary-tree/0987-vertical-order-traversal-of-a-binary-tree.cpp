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
   // save each node with info like xaxis and level and data in sorted form 
   // first lvl sorting done based on x axis second is done on y axis
    void bfs(TreeNode* root, map<int, map<int, multiset<int>>> &mp ) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int lvl =0;
        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; i++) {
                auto curr = q.front();
                q.pop();
                TreeNode *node = curr.first;
                int x = curr.second;
                mp[x][lvl].insert(node->val);
                if(node->left) {
                    q.push({node->left, x-1});
                }
                if(node->right) {
                    q.push({node->right, x+1});
                }
            }
            lvl++;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        /** multi set is nothing but an array that is sorted, heap sort is not stable so, either use array and sort manaully or use multiset so usint it */
        /** Using map bcz it is sorted  */
        // map<xasix , map<yaxis, sortedArray>>
        map<int, map<int, multiset<int>>> mp;
        vector<vector<int>> res;
        if(!root) return res;
        int lvl = 0;
        bfs(root, mp);
        for(auto &[x, lvlmap]: mp) {
            vector<int> lvlRes;
            for(auto &[y, mset]: lvlmap) {
               for(auto val: mset) {
                lvlRes.push_back(val);
               } 
            }
            res.push_back(lvlRes);
        }
        return res;
    }
};