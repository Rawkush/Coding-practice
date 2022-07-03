#include <iostream>
using namespace std;
	template <typename T>
	class BinaryTreeNode {
    	public:
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;

    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

class Pair{
  public:
  Node *head;
  Node *tail;
  Pair(){
    head=NULL;
    tail=NULL;
  }
  Pair(Node *head, Node *tail) {
    this->head = head;
    this->tail = tail;
  }
};
Pair * buildList(BinaryTreeNode<int>* root){
  if(root==NULL) return NULL;
  // if(root->left==NULL && root->right==NULL) return new Pair( new Node<int>(root->data));
  Pair* left = buildList(root->left);
  Pair * right = buildList(root->right);
  Node<int> *newNode = new Node<int>(root->data);
  Pair * current =  new Pair(newNode, newNode);

  if(left!=NULL && left->head!=NULL){
    current->head=left->head;
    left->tail->next=newNode;
  }
  if(right!=NULL && right->head!=NULL){
      current->tail->next=right->head;
      current->tail=right->tail;
  }
  return current;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
  if(root==NULL) return NULL;
  return buildList(root)->head;
}
