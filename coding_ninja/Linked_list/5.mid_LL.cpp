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


int main()
{
    Node *head=NULL;
    Node n1(1),n2(2),n3(3),n4(4);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=NULL;

    head=&n1;
    printReverse(head);
    return 0;
}
