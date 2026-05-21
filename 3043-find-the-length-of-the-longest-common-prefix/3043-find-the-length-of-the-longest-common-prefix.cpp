class Node {
    public:
    char c;
    bool term;
    unordered_map<char, Node*> mp;
    Node() {
        c= '\0';
        term=false;
    }
};

class Solution {
public:
    void insert( Node *root, string s) {
        for(int i=0; i<s.size(); i++) {
            /** if there is no node create new insert and move */
            if(root->mp.find(s[i])==root->mp.end()) {
                Node *node = new Node();
                node->c = s[i];
                root->mp[s[i]] = node;
                root=node;
            } else {
                root = root->mp[s[i]];
            }
            if(i==s.size()-1) {
                root->term = true;
            }
        }
    }

    bool existsInTrie(Node *root, string s) {
        for(int i=0; i<s.size(); i++) {
            if(root->mp.find(s[i]) == root->mp.end()) return false;
            root = root->mp[s[i]];
        }
        return true;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node *root = new Node(); // parent node;
        // Node *node =root;
        for(auto x: arr1) {
            string s = to_string(x);
            insert(root, s);
        }
        int mx = 0;

        for(auto x: arr2) {
            string s = to_string(x);
            string ts = "";
            for(int i=0; i<s.size(); i++) {
                ts+=s[i];
                if(existsInTrie(root, ts)) {
                    mx = max(mx, i+1);
                }
            }
        }
        return mx;
    }
};