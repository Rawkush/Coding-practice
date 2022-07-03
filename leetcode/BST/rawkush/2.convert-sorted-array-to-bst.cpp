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
    TreeNode* build(vector<int>& nums, int low, int high){
      if(low>high) return NULL;
      int mid = ceil((low+high)/2);

      TreeNode *root = new TreeNode(nums[mid]);
      TreeNode * left = build(nums, low, mid-1);
      TreeNode * right = build(nums, mid+1, high);
      root->left=left;
      root->right=right;
      return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
      if(nums.size()==0) return NULL;
      if(nums.size()==1) return new TreeNode(nums[0]);
      return build(nums, 0, nums.size()-1);
    //  return NULL;
    }
};