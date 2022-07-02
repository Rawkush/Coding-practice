#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T>
class TreeNode{
  public:
  T data;
  vector<TreeNode*> children;
  TreeNode(T data){
    this->data = data;
  }
};



TreeNode<int>* createTree(){
  int rootData;
  cout<<"Enter root data: ";
  cin >> rootData;
  queue<TreeNode<int>*> pendingNodes;
  TreeNode<int> *rootNode =  new TreeNode<int>(rootData);
  pendingNodes.push(rootNode);
  while(!pendingNodes.empty()){
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    int numChildren;
    cout<<"Enter number of children of "<<front->data<<" : ";
    cin >> numChildren;
    for(int i=0;i<numChildren;i++){
      //numChildren--;
      int childData;
      cout<<"Enter "<<i+1<<"th child of "<<front->data<<" : ";
      cin >> childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      pendingNodes.push(child);
      front->children.push_back(child);
    }
  }
  return rootNode;
}



void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
      TreeNode<int> *front = pendingNodes.front();
      pendingNodes.pop();
      cout<<"For node :"<< front->data<<" ";
      for(int i=0;i<front->children.size(); i++){
        pendingNodes.push(front->children[i]);
        cout<<front->children[i]->data;
        if(i+1!=front->children.size()) cout<<",";
      }
      cout<<endl;
    }
}

int sumNodes(TreeNode<int> *root){
  if(root==NULL) return 0;
  int sum=0;
  for(int i=0;i<root->children.size();i++){
    sum += sumNodes(root->children[i]);
  }
  return sum+root->data;
}



class Pair{
  public:
  int depth;
  TreeNode<int> *root;
  Pair(TreeNode<int> * root, int depth){
    this->root = root;
    this->depth = depth;
  }
};

//1 1 2 1 3 1 4 1 5 0

void replace(TreeNode<int>* root, int depth){
  root->data= depth;
  for(int i=0;i<root->children.size();i++){
    replace(root->children[i], depth+1);
  }
}

void replaceWithDepthValue(TreeNode<int>* root) {
  if(root==NULL) return;
  replace(root, 0);
}




int main(){
  TreeNode<int>* rootNode = createTree();
  //printLevelWise(rootNode);
  replaceWithDepthValue(rootNode);
  printLevelWise(rootNode);

  //cout<<"Sum of nodes "<<sumNodes(rootNode)<<endl;
}