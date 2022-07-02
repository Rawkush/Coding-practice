#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};



Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *newList=NULL;
    Node *head3 = NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data==head2->data){
            Node *node = new Node(head1->data);
                if(newList==NULL){
                node->data=head1->data;
                newList=node;
                head3=node;

            }else{
                node->data=head1->data;
                head3->next=node;
                head3=head3->next;
            }
            head1=head1->next;
            head2= head2->next;
        }else
        if(head1->data>head2->data){
            head2=head2->next;
        }else{
            head1=head1->next;
        }
    }
    return newList;
}
void print(Node *n)
{
    while(n!=NULL)
    {
        cout<< n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}
int main(){
   Node *head=NULL;
    Node n1(1),n2(2),n3(3),n4(4);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=NULL;
    head=&n1;

   Node *head2=NULL;
    Node a1(0),a2(2),a3(3),a4(40);
    a1.next=&a2;
    a2.next=&a3;
    a3.next=&a4;
    a4.next=NULL;
    head2=&a1;
Node* test=findIntersection(head,head2);
    print(test);
  return 0;
}