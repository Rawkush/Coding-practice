  bool isCompleteTree(TreeNode* root) {
      if(root==NULL) return true;
      bool cbtEnd=false;
      queue<TreeNode*> pendingNodes;
      while(!pendinNodes.empty()) {
        TreeNode* front = pendingNodes.top();
        pendingNodes.pop();
        if(cbtEnd && (root->left || root->right)) return false;
        if(front->left)  pendinNodes.push(front->left);
        if(root->right) pendingNodes.push(root->right);
        if(root->left ==NULL || root->right==NULL)  cbtEnd=true;
      }
      return true;
    }