int level (TreeNode * root, TreeNode * target,int k, vector<int> &distance){
  if(root==NULL) return -1;
  if(root==target){
      elementsAtDistanceKFromRoot(target, k, distance);
      return 1;
  }
  int left = level(root->left, target, k, distance);
  int right = level(root->right, target,k,distance);
  if(left==-1 && right==-1) return -1;
  int height =max(left,right);
  if(k-height==0) {
      distance.push_back(root->val);
      return right +1;
  }
  if(left ==-1){
    elementsAtDistanceKFromRoot(root->left, k-height-1, distance);
  }
  if(right ==-1){
    elementsAtDistanceKFromRoot(root->right, k-height-1, distance);
  }
  return height +1;
}

void elementsAtDistanceKFromRoot (TreeNode * root, int k, vector<int> & distance){
  if(root==NULL) return;
  if(k<0) return;
  if(k==0) {
    distance.push_back(root->val);
    return;
  }
  elementsAtDistanceKFromRoot(root->left, k-1, distance);
  elementsAtDistanceKFromRoot(root->right, k-1, distance);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  vector<int> distance;
  level(root, target,k, distance);
  return distance;
}