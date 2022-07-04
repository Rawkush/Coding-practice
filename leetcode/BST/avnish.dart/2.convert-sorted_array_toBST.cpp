class Solution {

    TreeNode* arrayToBST(vector<int>& nums,int start, int end ) { 
       
       if(start>end) return NULL;
    
       int mid= (start+end)/2;
        
       TreeNode* node=new TreeNode(nums.at(mid));
        
      
       node->left=arrayToBST(nums,start,mid-1);
      
    
      node->right=arrayToBST(nums,mid+1,end);
        
      return node;
    
    }
    
    public:
    TreeNode* sortedArrayToBST(vector<int>& nums) { 
      return arrayToBST(nums,0,nums.size()-1);
    }
};