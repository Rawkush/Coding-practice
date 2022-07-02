#include<iostream>
#include<queue>
using namespace std;

	template <typename T>
	class BinaryTreeNode {
    	public :
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};



void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
  if(root == NULL) return;
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  pendingNodes.push(NULL);
  while(!pendingNodes.empty()) {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    if(front==NULL){
      cout<<endl;
      if(!pendingNodes.empty())pendingNodes.push(NULL);
      continue;
    }
    cout << front->data << " ";
    if(front->left) pendingNodes.push(front->left);
    if(front->right) pendingNodes.push(front->right);
  }
}

BinaryTreeNode<int>* takeInputLevelWise(){
  int rootData ;
  cout<<"Enter root Data: ";
  cin>>rootData;
  if(rootData==-1) return NULL;
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(!pendingNodes.empty()){
    BinaryTreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter left child of "<<front->data<<endl;
    int leftChildData;
    cin>>leftChildData;
    if(leftChildData!=-1){
      BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
      front->left=child;
      pendingNodes.push(child);
    }
    cout<<"Enter right child of "<<front->data<<endl;
    int rightChildData;
    cin>>rightChildData;
    if(rightChildData!=-1){
      BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
      front->right=child;
      pendingNodes.push(child);
    }
  }
  return root;
}


vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {

    // Write your code here
  vector<Node<int>*> result;
    if(root==NULL) return result;
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  pendingNodes.push(NULL);
  Node<int> *head= NULL;
  Node<int> *tail= NULL;
  while(!pendingNodes.empty()) {
    BinaryTreeNode<int> * front = pendingNodes.front();
    pendingNodes.pop();
    if(front==NULL) {
      if(pendingNodes.empty()){
          if(head!=NULL) result.push_back(head);
          break;
      }
      result.push_back(head);
      head=NULL;
      tail=NULL;
      pendingNodes.push(NULL);
      continue;
    }

    if(front->left) pendingNodes.push(front->left);
    if(front->right) pendingNodes.push(front->right);
    if(head ==NULL){
      head=new Node<int>(front->data);
      tail=head;
    }else{
      tail->next= new Node<int>(front->data);
      tail=tail->next;
    }
  }

  return  result ;
}




int main(){
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
  BinaryTreeNode<int> *node3 = new BinaryTreeNode<int>(4);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  printLevelWise(root);
}