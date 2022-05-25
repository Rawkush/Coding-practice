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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *fhead, *ftail;
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    if(head1->data<head2->data)
    {
        fhead=head1;
        ftail=head1;
        head1=head1->next;
    }
    else
    {
        fhead=head2;
        ftail=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            ftail->next=head1;
            ftail=ftail->next;
            head1=head1->next;
        }
        else
        {
            ftail->next=head2;
            ftail=ftail->next;

            head2=head2->next;
        }
    }

    if(head1!=NULL)
    {
        ftail->next=head1;
    }
    if(head2!=NULL)
    {
        ftail->next=head2;
    }
    return fhead;
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
int main()
{
    Node *head=NULL;
    Node n1(1),n2(2),n3(3),n4(4);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=NULL;
    head=&n1;
    print(head);

    Node *head2=NULL;
    Node a1(12),a2(22),a3(23),a4(41);
    a1.next=&a2;
    a2.next=&a3;
    a3.next=&a4;
    a4.next=NULL;
    head2=&a1;
    print(head2);
    Node *h;
    h = mergeTwoSortedLinkedLists(head, head2);
    print(h);

    return 0;
}
