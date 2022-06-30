
class Solution {

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> output;
    if(root==NULL) return output;
           
    queue<TreeNode*> q;
    TreeNode* a= NULL;
    bool value=true;  // to keep track for zigzag motion
        
    q.push(root);
    
    a=root->left==NULL?root->right:root->left;
    
    
        
    vector<int> currentOutput;
    while(!q.empty()){
          
            TreeNode* top=q.front();
            // this means we come to new level
             if(top==a){
                if(currentOutput.size()!=0) {
                 
                 if(!value){
                  reverse(currentOutput.begin(), currentOutput.end());}
                  
                  output.push_back(currentOutput);  
                  currentOutput.clear();
                  }
                 a=NULL;
                 value=!value;
                
            }
            
            
            currentOutput.push_back(top->val);
            q.pop();
        
       
        
           if(top->left!=NULL)
            q.push(top->left);
            if(top->right!=NULL)
            q.push(top->right);
           
        
            if(a==NULL){ 
               
             a=top->left==NULL?top->right:top->left;
             
            }  
       
    }
    
    
     if(currentOutput.size()!=0) {
          
                  if(!value) reverse(currentOutput.begin(), currentOutput.end());
                
                  output.push_back(currentOutput);   
                  currentOutput.clear();
     }  
        
         return output;
       
    }
    
   
};