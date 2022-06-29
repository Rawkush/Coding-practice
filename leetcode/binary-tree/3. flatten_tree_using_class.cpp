class Tree{
    public:
    TreeNode* root;
    TreeNode* leaf;
    
    Tree(TreeNode* root){
        this->root=root;
        this->leaf=NULL;
    };
      
};

class Solution {
    Tree* myFunc(TreeNode* root){
         if(root==NULL) return new Tree(NULL);
        
         Tree* currentTree= new Tree(root);
        if(root->left==NULL && root->right==NULL) 
            currentTree->leaf=root;
        
        
         Tree* leftnode= myFunc(root->left);
         Tree* rightnode= myFunc(root->right);
         
        
         if(leftnode->root!=NULL){
             leftnode->leaf->right=rightnode->root;
             currentTree->root->right=leftnode->root;
             currentTree->root->left=NULL;
         } else if(rightnode->root!=NULL){
             currentTree->root->right=rightnode->root;    
            }
       
        
        // for changing leaf node
        if(rightnode->leaf!=NULL) currentTree->leaf=rightnode->leaf;
        else if(leftnode->leaf!=NULL){
            currentTree->leaf=leftnode->leaf;
        }
        
           
        return currentTree;
         
    }
    
public:
    void flatten(TreeNode* root) {
        
         myFunc(root);
    }
};