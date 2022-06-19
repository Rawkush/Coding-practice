#include<iostream>
using namespace std;


TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x){

    if(root==NULL) return NULL;

    TreeNode<int> *largeElement=NULL;

    if(root->data>x) largeElement=root;

    for(int i=0; i<root->children.size();i++){
        TreeNode<int> *tmpLarge = getNextLargerElement(root->children[i],x);
        if(largeElement->data>tmpLarge->data || largeElement==NULL ){
            largeElement=tmpLarge;
        }
    }
    return largeElement;
}