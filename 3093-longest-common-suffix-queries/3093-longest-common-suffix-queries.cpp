class Node {
    public:
        vector<int> nextNode;  // remove (26) from here
        int idx;
        int size;
        Node(int i, int s) : nextNode(26, -1) {  // initialize here
            idx = i;
            size = s;
        }
};

class Solution {
public:

    vector<Node*> trieNodes;

    void addInTrie(string &s, int idx, Node *root) {
        int size = s.size();
        for(int i=size-1; i>=0; i--) {
            /** if there is no node create new insert and move */
            if(root->nextNode[s[i]-'a']==-1) {
                Node *node = new Node(idx, size);
                trieNodes.push_back(node);
                int trieNodeIdx = trieNodes.size()-1;
                root->nextNode[s[i]-'a'] = trieNodeIdx;
                root=node;
            } else {
                /** if node exists check if current string size if small or not */
                root = trieNodes[root->nextNode[s[i]-'a']];
                if(root->size > size ) {
                    root->size = size;
                    root->idx = idx;
                }
            }         
        }
    }

    int existsInTrie(Node *root, string &s) {
        int idx =-1;
        for(int i=s.size()-1; i>=0; i--) {
            if(root->nextNode[s[i]-'a'] == -1) return idx;
            root = trieNodes[root->nextNode[s[i]-'a']];
            idx = root->idx;
        }
        return root->idx;
    }



    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Node *root = new Node(0, INT_MAX);
        trieNodes.push_back(root);

        int smallestStringIdx = 0;
        int smallestStringSize = INT_MAX;
        for(int i=0; i<wordsContainer.size(); i++) {
            addInTrie(wordsContainer[i], i, root);
            if(smallestStringSize > wordsContainer[i].size()) {
                smallestStringIdx = i;
                smallestStringSize = wordsContainer[i].size();
            }
        }

        vector<int> res(wordsQuery.size(), smallestStringIdx);
        for(int i=0; i<wordsQuery.size(); i++) {
            // string s ="";
            // for(int j=wordsQuery[i].size()-1; j>=0; j--) {
                // s+=wordsQuery[i][j];
            int idx = existsInTrie(root, wordsQuery[i]);
            if(idx==-1) {
                continue;
            }
            res[i] = idx;
            // }
        }
        // printMap(mp);
        return res;
    }
};