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

Node* insertNode(Node *head, int i, int data)
{
    if(head==NULL && i!=0)
        return head;
    if(i<=0||head==NULL)
    {
        Node *n = new Node(data);
        n->next=head;
        head=n;
        return head;
    }

    head->next=insertNode(head->next, i-1, data);
    return head;
}

void print(Node *n)
{
    while(n!=NULL)
    {
        cout<< n->data<<" ";
        n=n->next;
    }
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
    head=insertNode(head,30, 33);
    print(head);
    return 0;
}

