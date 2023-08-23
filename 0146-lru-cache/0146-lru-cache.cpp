class Node{
  public:
  int val;
  int key;
  Node *next;
  Node* prev;
  Node(int _key, int data){
    val = data;
    next =NULL;
    prev = NULL;
    key = _key;
  }
};
class LRUCache {
public:

    int size;
    int msize;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
      size=0;
      msize = capacity;
      head = NULL;
      tail= NULL;
    }
    
    int get(int key) {
      if(mp.find(key)==mp.end()){
        return -1;
      }
      // get node and bring it on head;
      Node* curr = mp[key];
      refresh(curr);
      return curr->val;
    }

    void print(Node* thead){
      while(thead){
        cout<<thead->val<<" -> ";
        thead=thead->next;
      }
      cout<<endl;
    }

    void refresh(Node *curr){
      // print(head);
      if(!head){
        head = curr;
        tail = curr;
        if(msize > size) size++;
        return;
      }
      if(curr == head){
        return;
      }
      if( curr == tail){
        tail = curr->prev;
        curr->prev=NULL;
        tail->next =NULL;
        curr->next = head;
        head->prev = curr;
        head= curr;
        return;
      }

      // it means a new node is being added
      if(curr->next ==NULL && curr->prev==NULL){
        curr->next = head;
        head->prev = curr;
        head = curr;
        if(msize > size) size++;
        return;
      }
      

      //mid element
        Node* prev = curr->prev;
        Node* next = curr->next;
        curr->prev = NULL;
        curr->next = NULL;

        prev->next = next;
        next->prev = prev;

        curr->next = head;
        head->prev = curr;
        head = curr;
    }

    

    void put(int key, int value) {
      
      // trying to insert  a new element
      if(mp.find(key)==mp.end()){
        Node* curr = new Node(key, value);
        mp[key] = curr;
        //if msize ==size remove tail
        // cout<<"size " <<size<< " val "<< key<<endl;
        if(msize == size){
          Node *last = tail;
          tail = tail->prev;
          if(tail)
            tail->next = NULL;
          else{
            head =NULL;
            size--;
          }
          last->prev = NULL;
          mp.erase(last->key);
          delete last;
        }
        refresh(curr); // this will the new node
      }else{

        // updating existing data, so no need to delete anything;

        Node *curr = mp[key];
        curr->val = value;
        refresh(curr);
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */