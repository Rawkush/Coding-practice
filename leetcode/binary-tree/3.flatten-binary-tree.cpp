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
    if(postLength==0) return NULL;
  BinaryTreeNode<int> *root = new  BinaryTreeNode<int>(postorder[postLength-1]);
  int i=0;
  for(;i<inLength;i++){
    if(inorder[i]==postorder[postLength-1]) break;
  }

  BinaryTreeNode<int>*left = buildTree(postorder, i, inorder, i);
  BinaryTreeNode<int>*right = buildTree(postorder+i,postLength-i-1,inorder+i+1,postLength-i-1);

  root->left=left;
  root->right=right;
  return root;
}

 TreeNode *flat(TreeNode * root){
     if(root==NULL) return NULL;
     if(root->left==NULL && root->right==NULL) return root;
      TreeNode *left= root->left;
      TreeNode *right = root->right;

      TreeNode *leftLeaf= flat(root->left);
      TreeNode *rightLeaf= flat(root->right);
      root->left=NULL;
      if(leftLeaf==NULL) return rightLeaf;
      root->right=left;
      leftLeaf->right=right;
     if(rightLeaf==NULL) return leftLeaf;
     return rightLeaf;

   }


    void flatten(TreeNode* root) {
       if(root==NULL)  return;
       flat(root);

    }


int main(){
  //BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
  // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
  // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
  // BinaryTreeNode<int> *node3 = new BinaryTreeNode<int>(4);
  // root->left = node1;
  // root->right = node2;
  // node1->left = node3;
  int postorder[]={4 ,5, 2, 6, 7 ,3, 1};
  int inorder[]={4 ,2 ,5 ,1 ,6, 3 ,7};
  BinaryTreeNode<int> * root = buildTree(postorder,7, inorder, 7);
  printLevelWise(root);
}