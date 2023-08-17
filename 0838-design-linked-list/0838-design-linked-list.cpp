class Node{
  public:
  int val;
  Node* next;
  Node(int data){
    val = data;
    next = NULL;
  }
};
class MyLinkedList {
public:
  Node* head;
  Node* tail;
  MyLinkedList() {
    head=NULL;
    tail=NULL;
  }
  
  int get(int index) {
    if(!head) return -1;
    int i = 0;
    // print(head);
    Node *ptr = head;
    while(ptr && i<index){
      ptr = ptr->next;
      i++;
    }
    if( i!=index || !ptr ) return -1;
    return ptr->val;
  }
  
  void addAtHead(int val) {
    // print(head);

    Node* newHead = new Node(val);
    if(!head){
      head= newHead;
      tail=newHead;
      return;
    }
    newHead->next = head;
    head = newHead;
  }
  
  void addAtTail(int val) {
      // print(head);

    Node* newTail =  new Node(val);
    if(!head){
      head=newTail;
      tail=newTail;
      return;
    }
    tail->next = newTail;
    tail =newTail;
  }
  
  void addAtIndex(int index, int val) {
    // print(head);

    int  i=0;
    if(index==0){
      addAtHead(val);
      return;
    }
    Node* newNode =  new Node(val);
    Node* prev = NULL;
    Node* itr = head;
    while(i!=index && itr){
      prev = itr;
      itr=itr->next;
      i++;
    }
    // cout<< i<<" : "<<prev->val;
    if(i!=index) return;
    newNode->next = prev->next;
    prev->next = newNode;
    if(!newNode->next) tail= newNode;
    // print(head);
  }
  
  void print(Node* tmp){
    while(tmp){
      cout<<tmp->val<<"->"; 
      tmp = tmp->next;
    }
    cout<<endl;
  }

  void deleteAtIndex(int index) {
    // print(head);
    if(!head) return;
    if(index==0 && head && !head->next){
      head=NULL;
      tail=NULL;
      return;
    }
    if(index == 0){
      Node* tmp = head->next;
      head= head->next;
      tmp->next = NULL;
      return;
    } 
    int i=0;
    Node* itr  =  head;
    Node* prev= NULL;
    while(i!=index && itr){
      prev= itr;
      itr=itr->next;
      i++;
    }
    // cout<<endl;
    // cout<<"i "<<i<<" : "<<prev->val;
    if(i!=index) return;
    if(!itr) return;
    prev->next = itr->next;
    if(!prev->next) tail=prev;
    itr->next =NULL;
    // delete itr;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */