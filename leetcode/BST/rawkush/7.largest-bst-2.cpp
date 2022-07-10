class Pair{
    public:
    bool isBST;
    int min;
    int max;
    int count;
    //int maxCount;
    Pair(){
        isBST = true;
        count = 0;
        min=INT_MAX;
        max=INT_MIN;
        //maxCount =0;
    }
};
Pair * largest(Node *root){
  if(root == NULL) return new Pair();
  Pair *currentPair = new Pair();
    currentPair->min=root->data;
    currentPair->max=root->data;

  if(root->left == NULL && root->right == NULL){
    currentPair->count=1;
    return currentPair;
  }

  Pair *leftPair = largest(root->left);
  Pair* rightPair = largest(root->right);


  if(leftPair-> isBST && rightPair-> isBST){
    if(root->data > leftPair->max && root->data < rightPair->min){
      currentPair->count = leftPair->count + rightPair->count + 1;
      currentPair->min = min(root->data,min(leftPair->min,rightPair->min));
      currentPair->max = max(root->data,max(leftPair->max,rightPair->max));
      return currentPair;
    }
  }
  currentPair->isBST = false;
  currentPair->min  = min(leftPair->min, min(root->data, rightPair->min));
  currentPair->max = max(rightPair->max, max(root->data, leftPair->max));
  currentPair->count = max(leftPair->count, rightPair->count);
  return currentPair;
}

int largestBst(Node *root){

  Pair *result = largest(root);
  return result->count;

}
