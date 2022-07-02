
class Output{
    public:
    int max=0;
    int value;
   
    Output(){
        this->value=0;
        this->max=0;}    
};

class Solution {
    
     Output* diameterOfTree(TreeNode* root) {
        if(root==NULL) return new Output();
        Output* output=new Output();
        
        Output* leftcount=diameterOfTree(root->left);
        Output* rightcount=diameterOfTree(root->right);   
        
        if(leftcount->max>output->max) output->max=leftcount->max;
        if(rightcount->max>output->max) output-> max=rightcount->max;
        
        if((leftcount->value+rightcount->value)>output->max){ 
           
           output-> max=(leftcount->value+rightcount->value);
            
        
        }
        
        output->value=(1+(leftcount->value>rightcount->value?leftcount->value:rightcount->value));
         
        return output;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
      Output* output= diameterOfTree(root);
    return output->max;
        
    }
};