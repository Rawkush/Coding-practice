#include<queue>
class CBTInserter {
public:
    TreeNode *root;
    queue<TreeNode*> pendingNodes;
    CBTInserter(TreeNode* root) {
      this->root = root;
      pendingNodes.push(root);
      while(!pendingNodes.empty()){
        TreeNode* front = pendingNodes.front();
        if(front->left && front->right){
          pendingNodes.push(front->left);
          pendingNodes.push(front->right);
          pendingNodes.pop();
          continue;
        }else
        if(front->left)  pendingNodes.push(front->left);
        break;
      }
    }

    int insert(int val) {
      TreeNode* front = pendingNodes.front();
      // while(front->left!=NULL && front->right!=NULL){
      //   front=pendingNodes.front;
      //   pendingNodes.pop();
      // }
      if(front->left ==NULL){
        front->left = new TreeNode(val);
        pendingNodes.push(front->left);
      }else
      if(front->right==NULL){
        front->right = new TreeNode(val);
        pendingNodes.push(front->right);
      }
      if(front->left!=NULL && front->right!=NULL){
        pendingNodes.pop();
      }
      return front->val;
    }

    TreeNode* get_root() {
      return root;
    }
};