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
void printTree(BinaryTreeNode<int> *root){
  if(root==NULL) return;
  cout<< root->data<<":";
  if(root->left) cout<<" L "<<root->left->data<<",";
  if(root->right) cout<<" R "<<root->right->data;
  cout<<endl;
  printTree(root->left);
  printTree(root->right);
}
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
   queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(!pendingNodes.empty()) {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout<<front->data<<":";
    if(front->left) {
      cout<<"L:"<< front->left->data;
      pendingNodes.push(front->left);
    }else cout<<"L:"<< -1;
    cout<<",";
    if(front->right) {
      pendingNodes.push(front->right);
      cout<<"R:"<<front->right->data;
    }else cout<<"R:"<< -1;
    cout<< endl;
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


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
  // Write your code here
  if(inLength==0) return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(postorder[postLength-1]);
     
    int i=0;
     // cout<<"val:"<<i<<inLength;
    for(i=0; i<inLength; i++){
       
        if(inorder[i]==root->data)
        break;
        
    }
    
    
    
    root->left = buildTree(postorder,i,inorder, i);
    root->right = buildTree(postorder+i,postLength-i-1,inorder+i+1,postLength-i-1);     
    return root;  
}

int main(){
  int postOrder[]={4, 2, 5, 1,3 };
  int inorder[]={4,5,2,3,1 };
  BinaryTreeNode<int> * root = buildTree(inorder,5, postOrder, 5);
  printLevelWise(root);
  return 0;
}