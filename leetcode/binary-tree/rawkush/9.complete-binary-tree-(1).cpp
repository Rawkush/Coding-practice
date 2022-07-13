  bool isCompleteTree(TreeNode* root) {
      if(root==NULL) return true;
      // bool cbtEnd=false;
      queue<TreeNode*> pendingNodes;
      pendingNodes.push(root);
      while(!pendingNodes.empty()) {
        TreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        if(front==NULL && !pendingNodes.empty()){
          if(pendingNodes.front()==NULL) continue;
          return false;
        }
        if(front==NULL && pendingNodes.empty()) break;
        if(front->left==NULL && front->right!=NULL) return false;
        pendingNodes.push(front->left);
        pendingNodes.push(front->right);
      }
      return true;
    }