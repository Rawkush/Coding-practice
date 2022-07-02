#include <iostream>
using namespace std;
    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

class SumNode{
  public:  TreeNode<int> *node;
    int sum;
    SumNode(TreeNode<int> *node, int sum){
       this->node= node;
       this->sum=sum;
    }
};

SumNode* getNode(TreeNode<int> *root){
    if(root==NULL) return NULL;
    int sum= root->data;
    for(int i=0; i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    SumNode *maxNode = new SumNode(root, sum);
    for(int i=0; i<root->children.size();i++){
        SumNode *newNode=getNode(root->children[i]);
        if(maxNode->sum<newNode->sum) maxNode=newNode;
    }
    return maxNode;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    return getNode(root)->node;
}

int main(){

  return 0;
}