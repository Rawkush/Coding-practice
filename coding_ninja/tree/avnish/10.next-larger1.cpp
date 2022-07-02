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
    TreeNode<int> *sMax;
    Pair( TreeNode<int> * max,  TreeNode<int> * sMax){
        this->max=max;
        this->sMax=sMax;
    }
};

Pair* getLargest(TreeNode<int>* root){
    if(root==NULL) return NULL;

    Pair current= new Pair(root, NULL);


    for(int i=0;i<root->children.size();i++){
        Pair *temp= getLargest(root->children[i]);

          if(temp->max->data>current->max->data){
           // we are checking the current->max and temp->sMax to check for maximum.
            if(temp->sMax!=NULL){
                current->sMax=current->max->data>temp->sMax->data ? current->max: temp->sMax;
            } else
            current->sMax=current->max;

            current->max= temp->max;
          }

        else if(current->sMax==NULL) {

            // if temp->max is equal to current->max then we can't assign the current-> sMax to temp->max
            //because the max and sMax cannot be same
            if(temp->max->data<current->max->data) current->sMax=temp->max;
        }

        else if(temp->max->data>current->sMax->data && temp->max->data<current->max->data ){
                current->sMax=temp->max;
            }

    }


    return current;
 }

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL) return NULL;
    Pair *result = getLargest(root);
    return result==NULL?NULL:result->sMax;
}

int main(){
  TreeNode<int>* rootNode = createTree();
  printLevelWise(rootNode);
  getSecondLargestNode(rootNode);
  //cout<<"Sum of nodes "<<sumNodes(rootNode)<<endl;
}