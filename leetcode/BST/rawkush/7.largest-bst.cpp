
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Pair{
  public:
  int max;
  int min;
  bool isBST;
  int count;
  Pair(){
    max=0;
    min=0;
    count=0;
    isBST=true;
  }
};

Pair * largest(Node *root){

  if(root==NULL) return new Pair();
  if(root->left == NULL && root->right == NULL){
    Pair *newPair = new Pair();
    newPair->max=root->data;
    newPair->min=root->data;
    newPair->count=1;
    return newPair;
  }
  Pair *leftPair = NULL;
  Pair *rightPair = NULL;
  Pair *currentPair = new Pair();
  currentPair->max=root->data;
  currentPair->min=root->data;

  if(root->left) leftPair = largest(root->left);
  if(root->right) rightPair = largest(root->right);

  if(leftPair && rightPair ){
    if(leftPair->isBST && rightPair->isBST && root->data > leftPair->max && root->data < rightPair->min){
      currentPair->count= leftPair->count + rightPair->count +1;
    }else currentPair->isBST=false;
    currentPair->count= max(currentPair->count, max(rightPair->count, leftPair->count));
    currentPair->max = max(root->data, max(leftPair->max, rightPair->max));
    currentPair->min = min(root->data, min(leftPair->min, rightPair->min));
    return currentPair;
  }
  if(leftPair){
    if(leftPair->isBST && leftPair->max < root->data) currentPair->count = leftPair->count + 1;
    else currentPair->isBST = false;
    currentPair->min = min(leftPair->min, root->data);
    currentPair->max = max(root->data,leftPair->max);
    currentPair->count= max(currentPair->count, leftPair->count);
    return currentPair;
  }
  if(rightPair){
    if(rightPair->isBST && rightPair->min > root->data) currentPair->count = rightPair->count + 1;
    else currentPair->isBST = false;
    currentPair->min = min(rightPair->min, root->data);
    currentPair->max = max(root->data,rightPair->max);
    currentPair->count= max(currentPair->count, rightPair->count);
    return currentPair;
  }

  return currentPair;
}

int largestBst(Node *root){
  if(root==NULL) return 0;
  int maxCount = 0;
  Pair *result = largest(root);
  return result->count;
}