// class ListNode {
//     public:
//     int data;
//     ListNode *next;
//     ListNode *prev;
//     ListNode(int dd) {
//         data=dd;
//         prev = NULL;
//         next = NULL;
//     }
// };

class Node {
    public:
    int f;
    list<int> el; // elements with val freequency f
    Node *prev;
    Node *next;
    Node(int v) {
        f= v;
        next = NULL;
        prev = NULL;
    }
};



class LFUCache {
public:
    int mx;
    Node *head;
    // unordered_map<int,pair<int,pair<list<int>::iterator, Node*>>> elf; // key, value, ListNode with value data, Node * with frequency data

    unordered_map<int,int> keyPair; //for key what is data
    unordered_map<int,Node*> elf; // elemtn to freeqeuncy
    unordered_map<int,list<int>::iterator> lf; //list insdie freequcny 
    LFUCache(int capacity) {
        mx = capacity;
        head = NULL;
    }
    
    void deleteNode(Node *node) {
        if(node == NULL) return;
        //if head
        if(node == head) {
            head = head->next;
            if (head) head->prev = NULL;
        } else if(node->next == NULL){ // tail
            Node *n = node->prev;
            n->next=NULL;
            node->prev = NULL;
        } else {
            //mid elements
            Node*p = node->prev;
            node->prev = NULL;
            p->next = node->next;
            node->next->prev =p;
            node->next = NULL;
        }
    }

    void deleteKey(int key) {
        elf.erase(key); 
        keyPair.erase(key);
        lf.erase(key);
    }

    void pop() {
        if(!head) return;
        int elementToDelete = head->el.front(); // first item in LFU in LRU order
        head->el.pop_front(); // delete this element
        deleteKey(elementToDelete);

        if(head->el.empty()) {
            deleteNode(head);
        }
        return;
    }

    void increaseFreequency(int element) {
        Node *cfnode = elf[element]; // current freequency node
        // remove item from current freequency node
        auto lfNode = lf[element]; // present inside freequncy node lsit
        
        cfnode->el.erase(lfNode); // delete the current element from freequency node's list using iterator which is O(1)

        Node *nextNode = cfnode->next;
        if(nextNode==NULL || nextNode->f!=cfnode->f+1) {
            Node *newNode = new Node(cfnode->f+1);
            newNode->el.push_back(element);
            cfnode->next = newNode;
            newNode->prev = cfnode;
            newNode->next = nextNode;
            if(nextNode) {
                nextNode->prev = newNode;
            }
            elf[element] = newNode;
            lf[element] = newNode->el.begin(); // as only one item is there
        } else {
            // if next node with f+1 already exists
            nextNode->el.push_back(element); //put it last this if for to maintain LRU for tie breaker
            elf[element] = nextNode;
            list<int>::iterator it = nextNode->el.end();
            it--;
            lf[element] = it;
        }

        // if current node is empty delete it
        if(cfnode->el.empty()) {
            //delete this node
            deleteNode(cfnode);
        }
        return;
    }

    int get(int key) {
        if(elf.count(key) <= 0) return -1; // cache miss
        // if key exists inrease its freequency
        increaseFreequency(key);
        return keyPair[key];
    }
    
    void put(int key, int value) {
        if(mx<=0) return;
        keyPair[key] = value;
        if(elf.count(key) > 0) {
            //element exists
            // so update the and increse the frequency
            increaseFreequency(key);
        } else {
            // key does not exists
            if(elf.size()>=mx) {
                pop();
            }
            // insert the element
            if(head==NULL || head->f!=1) {
                Node *newNode = new Node(1);
                if(!head) head = newNode;
                else {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                newNode->el.push_back(key);

                elf[key] = newNode;
                lf[key] = newNode->el.begin(); //as new node
            } else {
                //head has f ==1
                head->el.push_back(key);
                list<int>::iterator it = head->el.end();
                it--; // get last node which we inserted;
                elf[key] = head;
                lf[key] = it;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */