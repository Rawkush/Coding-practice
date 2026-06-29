/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int elementsAbove(TreeNode* root, TreeNode* target, int k, vector<int> &res) {
        if(!root) return -1;
        if(root==target) return 0;
        if(k<0) return -1;
        int d1 = elementsAbove(root->left, target, k, res);
        int d2 = elementsAbove(root->right, target, k, res);
        if(d1 == -1 && d2 ==-1) return -1;
        int distanceFromCurrentNode = max(d1,d2) +1;
        if(k==distanceFromCurrentNode) {
            res.push_back(root->val);
            return distanceFromCurrentNode;
        }
        if(k < distanceFromCurrentNode) {
            return distanceFromCurrentNode;
        }
        if(d1==-1) {
            // it means right side has the item, from this node we need to find remaing elements at k distance
            // subtraccting once more bcz we are going to left from curretn node
            elementInBottom(root->left, k-distanceFromCurrentNode -1, res);
        }
        if(d2 == -1) {
            elementInBottom(root->right, k-distanceFromCurrentNode -1, res);
        }
        return distanceFromCurrentNode;
    }

    void elementInBottom(TreeNode* root, int k, vector<int> &res) {
        if(!root) return;
        if(k==0) {
            res.push_back(root->val);
            return;
        }
        elementInBottom(root->left, k-1, res);
        elementInBottom(root->right, k-1,res);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        elementInBottom(target, k, res);
        elementsAbove(root, target, k, res);
        return res;
    }
};