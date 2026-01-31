/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node *helper(Node *node, unordered_map<Node*, Node*> &mp){
        if(node ==NULL) return NULL;
        if(mp.find(node)!=mp.end()) return mp[node];
        Node *newNode = new Node(node->val);
        mp[node] = newNode;
        for(int i=0; i< node->neighbors.size(); i++){
            Node *neighbor = helper(node->neighbors[i], mp);
            newNode->neighbors.push_back(neighbor);
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node* , Node*> mp;
        return helper(node, mp);
    }
};