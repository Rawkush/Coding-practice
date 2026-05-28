const int MAXNODES = 5e6;

class Node {
public:
    array<Node*, 26> nextNode;
    int idx;
    int size;
    Node(int i, int s) : idx(i), size(s) {
        nextNode.fill(nullptr);
    }
    Node() {}
};

Node pool[MAXNODES];
int poolIdx = 0;

Node* newNode(int i, int s) {
    pool[poolIdx].idx = i;
    pool[poolIdx].size = s;
    pool[poolIdx].nextNode.fill(nullptr);
    return &pool[poolIdx++];
}

class Solution {
public:
    void addInTrie(string &s, int idx, Node *root) {
        int size = s.size();
        for(int i=size-1; i>=0; i--) {
            if(root->nextNode[s[i]-'a'] == NULL) {
                Node *node = newNode(idx, size);
                root->nextNode[s[i]-'a'] = node;
                root = node;
            } else {
                root = root->nextNode[s[i]-'a'];
                if(root->size > size) {
                    root->size = size;
                    root->idx = idx;
                }
            }
        }
    }

    int existsInTrie(Node *root, string &s) {
        int idx = -1;
        for(int i=s.size()-1; i>=0; i--) {
            if(root->nextNode[s[i]-'a'] == NULL) return idx;
            root = root->nextNode[s[i]-'a'];
            idx = root->idx;
        }
        return root->idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        poolIdx = 0;  // reset pool for each test case
        Node *root = newNode(0, INT_MAX);

        int smallestStringIdx = 0;
        int smallestStringSize = INT_MAX;
        for(int i=0; i<wordsContainer.size(); i++) {
            addInTrie(wordsContainer[i], i, root);
            if(smallestStringSize > (int)wordsContainer[i].size()) {
                smallestStringIdx = i;
                smallestStringSize = wordsContainer[i].size();
            }
        }

        vector<int> res(wordsQuery.size(), smallestStringIdx);
        for(int i=0; i<wordsQuery.size(); i++) {
            int idx = existsInTrie(root, wordsQuery[i]);
            if(idx == -1) continue;
            res[i] = idx;
        }
        return res;
    }
};