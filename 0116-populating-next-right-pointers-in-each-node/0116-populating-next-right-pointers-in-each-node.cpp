/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node* connect(Node* root) {
    if(!root) return root;
    queue<Node*> mq;
    mq.push(root);
    while(!mq.empty()){
      int qSize=mq.size();
      Node* prev = NULL;
      for(int i=0;i<qSize;i++){
        Node *curr = mq.front();
        mq.pop();
        if(prev){
          prev->next = curr;
        }prev = curr;
        if(curr->left && curr->right){
          mq.push(curr->left);
          mq.push(curr->right);
          // curr->left->next = curr->right;
        }
      }
    }
    return root;
  }
};