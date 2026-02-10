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
    void inOrder(TreeNode*root, vector<int> &nodes) {
        if(root==NULL) return;
        inOrder(root->left, nodes);
        nodes.push_back(root->val);
        inOrder(root->right, nodes);
    }

    TreeNode* createTree(vector<int>&nodes, int l, int r) {
        if(l>r) return NULL;
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nodes[mid]);
        TreeNode* left = createTree(nodes, l, mid-1);
        TreeNode* right = createTree(nodes, mid+1, r);
        node->left = left;
        node->right = right;
        return node; 
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inOrder(root, nodes);
        //now i Have data in sorted form in nodes
        // in BST root -> left has smaler data and root -> right has biggerr data
        return createTree(nodes, 0, nodes.size()-1);
    }
};