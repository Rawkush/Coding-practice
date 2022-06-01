#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *n)
{
    while(n!=NULL)
    {
        cout<< n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}


Node *reverseLinkedListRec(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node * newHead=reverseLinkedListRec(head->next);
    Node *tail = head->next;
    tail->next=head;
    head->next=NULL;
    return newHead;
}

int main()
{
    Node *head=NULL;
    Node n1(1),n2(2),n3(3),n4(4);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=NULL;

    head=&n1;
    head= reverseLinkedListRec(head);
    print(head);
    return 0;
}
