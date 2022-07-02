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

int maxData(TreeNode<int> *root){
  if(root==NULL) return 0;
  int max=root->data;
  for(int i=0;i<root->children.size();i++){
    int oldMax= maxData(root->children[i]);
    if(oldMax>max) max=oldMax;
  }
  return max;
}
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
  if(root==NULL) return NULL;
  TreeNode<int>* max=root;
  for(int i=0;i<root->children.size();i++){
    TreeNode<int>*  oldMax= maxDataNode(root->children[i]);
    if(oldMax->data>max->data) max=oldMax;
  }
  return max;
}
int main(){
  TreeNode<int>* rootNode = createTree();
  printLevelWise(rootNode);
  cout<<"Max of nodes "<<maxData(rootNode)<<endl;
}