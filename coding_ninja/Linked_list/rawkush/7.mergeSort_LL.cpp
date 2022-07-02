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
Node *midPoint(Node *head)
{
    if(head==NULL||head->next==NULL) return head;
    Node *slow = head;
    Node *fast= head->next;
    while(fast!=NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    Node *tmp= slow->next;
    slow->next=NULL;
    return tmp;
}

Node *mergeSort(Node *head)
{
    //Write your code here
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node *mid = midPoint(head);
    print(head);
    print(mid);
    head = mergeSort(head);
    mid = mergeSort(mid);
    head= mergeTwoSortedLinkedLists(head, mid);
    print(head);
    return head;
}


int main()
{
    Node *head=NULL;
    Node n1(11),n2(21),n3(13),n4(4);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=NULL;
    head=&n1;
    // print(head);
    head= mergeSort(head);
    print(head);
    return 0;
}
