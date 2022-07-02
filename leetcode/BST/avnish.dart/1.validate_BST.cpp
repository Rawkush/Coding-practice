
class PairC{
    public:
    bool isBST=true;
    int min=INT_MAX;
    int max=INT_MIN;
   
};

class Solution {
    


PairC checkBst(TreeNode* root){
    PairC currentPair;
    currentPair.min=root->val;
    currentPair.max=root->val;
    
    if(root->left==NULL && root->right==NULL) return currentPair;
    
    PairC left;
    PairC right;
    
    if(root->left!=NULL)
    {left= checkBst(root->left);
      currentPair.isBST=left.isBST && left.max<root->val;
      
     currentPair.max= max(left.max,root->val);
     
     currentPair.min=min(left.min,root->val);
     
    }
    if(root->right!=NULL ){
    right= checkBst(root->right);
    currentPair.isBST=right.isBST && right.min>root->val;
     currentPair.max= max(right.max,currentPair.max); 
     currentPair.min=  min(right.min,currentPair.min);
    }
    
    if(root->right && root->left){
     currentPair.isBST=left.isBST && right.isBST && right.min>root->val &&left.max<root->val;
        
     currentPair.min=  min(min(left.min,right.min),root->val);
     currentPair.max= max(max(left.max, right.max),root->val);
    }

    
    return currentPair;
    
}
    
public:
    bool isValidBST(TreeNode* root) {
       return checkBst(root).isBST;
    }
};