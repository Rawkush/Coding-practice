/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node* copyRandomList(Node* head) {

    // tmp head
    Node * newHead = new Node(-1);
    Node * newTail = newHead;
    
    Node *itr = head;
    unordered_map<Node*, Node*> umap;

    // creating simple LL and mapping their address 
    while(itr){
      Node *newNode = new Node(itr->val);
      umap[itr] = newNode;
      newTail->next = newNode;
      newTail = newTail->next;
      itr = itr->next;
    }

    itr = head;
    Node* itr2 = newHead->next;
    while(itr){
      Node *randomNode = umap[itr->random];
      itr2->random = randomNode;
      itr2= itr2->next;
      itr= itr->next;
    }

    return newHead->next;
  }
};