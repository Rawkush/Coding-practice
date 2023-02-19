class Solution {
public:
  vector<int> getVector(){
    vector<int> v;
    return v;
  }
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<int> levelArray;
  vector<vector<int>> result;
  if(root==NULL) return result;
  queue<TreeNode*> pendingNodes;
  stack<TreeNode*> st;
  pendingNodes.push(root);
  pendingNodes.push(NULL);
  bool readLR=true;
  while(!pendingNodes.empty()){
    TreeNode* front = pendingNodes.front();
    pendingNodes.pop();

    if(front==NULL){
      if(pendingNodes.empty()){
        if(!levelArray.empty()) result.push_back(
          levelArray
        );
        break;
      }
      result.push_back(levelArray);
      levelArray=getVector();
      readLR=!readLR;
      pendingNodes.push(NULL);
      continue;
    }
    if(front->left) pendingNodes.push(front->left);
    if(front->right) pendingNodes.push(front->right);
    if(readLR){
      levelArray.push_back(front->val);
      if(front->left) st.push(front->left);
      if(front->right) st.push(front->right);
    }else{
      levelArray.push_back(st.top()->val);
      st.pop();
    }
  }
  return result;
}

};