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

int length(Node *head) {
    // Write your code here
    if(head==NULL)
        return 0;
    if(head->next==NULL)
        return 1;
    return 1+ length(head->next);
}
int main()
{
    Node n1(1),n2(2),n3(3),n4(4);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=NULL;
    cout<<length(&n1);
    return 0;
}
