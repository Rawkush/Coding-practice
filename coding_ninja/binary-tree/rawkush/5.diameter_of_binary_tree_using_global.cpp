class Solution {
    int max=0;
     int diameterOfTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        
        int leftcount=diameterOfTree(root->left);
        int rightcount=diameterOfTree(root->right);   
        
        if(leftcount>max) max=leftcount;
        if(rightcount>max) max=rightcount;
        
        if((leftcount+rightcount)>max){ 
           
            max=(leftcount+rightcount);
        
        }
        
       return 1+(leftcount>rightcount?leftcount:rightcount);
        
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
       diameterOfTree(root);
    return max;
        
    }
};