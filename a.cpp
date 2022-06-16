#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> preorder(Node* root, vector<int> * output=NULL){


  if(output==NULL) output= new vector<int>(0);
  if(root==NULL) return *output;

  output->push_back(root->data);
  preorder(root->left,output);
  preorder(root->right,output);
  return *output;
}

int main(){

  Node* root = new Node(1);

  cout<<preorder(root)[0];

  return 0;
}