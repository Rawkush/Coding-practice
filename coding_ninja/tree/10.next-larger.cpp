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
    if(root==NULL) return NULL;

    Pair *pair=NULL;
    for(int i=0;i<root->children.size();i++){
        Pair *newPair = getLargest(root->children[i]);
        if(pair==NULL){
            pair = newPair;
            continue;
        }
        if(pair->max->data<newPair->max->data){
            if(pair->smax!=NULL&&newPair->smax!=NULL&&pair->smax->data<newPair->smax->data){
                pair= newPair;
                continue;
            }
            pair->smax=pair->max;
            pair->max= newPair->max;
            //pair max =  newPair->max;
            continue;
        }
        if(pair->smax==NULL){
            pair->smax=newPair->smax;
            continue;
        }
        if(pair->smax->data<newPair->max->data){
            pair->smax= newPair->smax;
        }
    }

    // handle for root
    if(pair == NULL) return new Pair(root, NULL);
    if(root->data>pair->max->data){
        return new Pair(root, pair->max);
    }
    if(pair->smax==NULL){
        return new Pair(pair->max, root);
    }
    if(root->data>pair->smax->data) return new Pair(pair->max, root);
    return pair;
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