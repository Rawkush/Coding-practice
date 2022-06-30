#include<iostream>
#include<queue>
using namespace std;


vector<int> getVector(int size){
  vector<int> v(size);
  return v;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<int> levelArray;
  vector<vector<int>> result;
  if(root==NULL) return result;
  queue<TreeNode*> pendingNodes;
  pendingNodes.push(root);
  pendingNodes.push(NULL);
  bool readLR=true;
  int size=2;
  while(!pendingNodes.empty()){
    TreeNode* front = pendingNodes.front();
    pendingNodes.pop();

    if(front==NULL){
      if(pendingNodes.empty()){
        if(!levelArray.empty()) result.push_back(
          levelArray
        );
        break;
      }
      result.push_back(levelArray);
      levelArray=getVector(size);
      readLR=!readLR;
      pendingNodes.push(NULL);
      continue;
    }
    if(front->left){
      pendingNodes.push(front->left);
      size++;
    }
    if(front->right){
      pendingNodes.push(front->right);
      size++;
    };
    if(readLR){
      levelArray.push_back(front->val);
    }else{
      levelArray[--size]=front->val;
    }
  }
  return result;
}