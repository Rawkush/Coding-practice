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
    TreeNode<int> *max;
    TreeNode<int> *smax;
    Pair( TreeNode<int> * max,  TreeNode<int> * smax){
        this->max=max;
        this->smax=smax;
    }
};

Pair* getLargest(TreeNode<int>* root){
  Pair *largest=new Pair(root, NULL);
  for(int i=0;i<root->children.size();i++){
    Pair *tmp = getLargest(root->children[i]);
    if(tmp->max->data==largest->max->data){
      if(tmp->smax==NULL); else
      if (largest->smax==NULL) largest->smax=tmp->smax; else
      if (largest->smax->data<tmp->smax->data) largest->smax=tmp->smax;
      continue;
    }else
    if(tmp->max->data < largest->max->data){
      if(largest->smax==NULL) largest->smax=tmp->max; else
      if(tmp->max->data >= largest->smax->data)  largest->smax=tmp->max;
      // if(tmp->smax==NULL); else
      //if(tmp->smax->data> largest->smax->data) largest->smax=tmp->smax;
    } else
    if(tmp->max->data > largest->max->data){
      if(largest->smax==NULL){
        if(tmp->smax == NULL) largest->smax=largest->max; else
        if(largest->max->data>=tmp->smax->data) largest->smax= largest->max;
        else largest->smax = tmp->smax;
      } else
      if(tmp->smax==NULL){
        largest->smax=largest->max;
      } else
      if(tmp->smax->data > largest->max->data){
        largest->smax=tmp->smax;
      } else
        largest->smax=largest->max;

      largest->max= tmp->max;
    }
  }
  return largest;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL) return NULL;
    Pair *result = getLargest(root);
    cout<<"smax "<<result->smax->data<<endl;//>>
    cout<<"max "<<result->max->data<<endl;//>>
    return result->smax;
}

int main(){
  TreeNode<int>* rootNode = createTree();
  printLevelWise(rootNode);
  getSecondLargestNode(rootNode);
  //cout<<"Sum of nodes "<<sumNodes(rootNode)<<endl;
}