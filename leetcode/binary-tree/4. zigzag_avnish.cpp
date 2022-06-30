class Solution {

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> output;
    if(root==NULL) return output;
    vector<int> co; 
        
    queue<TreeNode*> q;
   
  
    bool isLeftRight=true;
        
    q.push(root);
    q.push(NULL);
    
    
    stack<TreeNode*>s;  
        
   
        
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();
        if(front==NULL){
            if(!co.empty()) output.push_back(co);
            
            co.clear();
            if(!q.empty()){
                q.push(NULL);
            } 
            isLeftRight=!isLeftRight;
        }
        
        else{
            
            if(!isLeftRight){
                TreeNode* top= s.top();
                s.pop();
                co.push_back(top->val);
            }
            else{
                co.push_back(front->val);
                if(front->left) s.push(front->left);
                if(front->right) s.push(front->right);
            }
            // always push that to queue
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            }
            
        }    
          return output;
          
     }
      
    };