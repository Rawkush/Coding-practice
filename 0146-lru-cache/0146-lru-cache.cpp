class Node{
  public:
  int val;
  int key;
  Node* prev;
  Node* next;
  Node(int _key, int _val){
    val= _val;
    key = _key;
    prev=NULL;
    next=NULL;
  }
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    int currSize;
    /**
    * key- Node pair
    */
    unordered_map<int,Node*> mp;
    
    LRUCache(int _capacity) {  
      capacity=_capacity;    
      head=NULL;
      tail=NULL;
      currSize=0;
    }
    
    void deleteNode(Node* node){
      if (node == head) {
        head = head->next;
        node->next=NULL;
        if (head) head->prev = NULL;
        if (node == tail) tail = NULL;  // In case it was the only node
        return;
      }

      if(node==tail){
        Node *newTail = tail->prev;
        if(newTail) newTail->next=NULL;
        tail->prev=NULL;
        tail=newTail;
        return;
      } 

      //middle element deletion
      Node*prev = node->prev;
      prev->next=node->next;
      node->next->prev = prev;
      node->next=NULL;
      node->prev=NULL;
      return;
    }

    void pushNode(Node*node){
      if(head==NULL){
        head=node;
        tail=node;
        return;
      }
      node->next=head;
      head->prev = node;
      node->prev=NULL;
      head=node;
    }

    int get(int key) {
      if(mp.find(key)==mp.end()){
        return -1;
      }
      /**
      * Node exists, so remove it from current position, and push it to top of queue
      */
      Node* node = mp[key];
      deleteNode(node);
      pushNode(node);
      return node->val;
    }
    
    void put(int key, int value) {
      Node*node = NULL;
      if(mp.find(key)!=mp.end()){
        node = mp[key];
        //no change is size;
        deleteNode(node);
        node->val=value;
        pushNode(node);
        return;
      }

      /**
      * if key does not exists
      */
      node = new Node(key, value);
      mp[key] = node;
      if(currSize>=capacity){
        mp.erase(tail->key);
        deleteNode(tail);
        pushNode(node);
      }else{
        currSize++;
        pushNode(node);
        if(tail==NULL) tail=head;
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */