// 5th problem statemnt solution

#include<iostream>
using namespace std;

class B;

class A
{
  int value;

public:

void  assign(int val) // for assigning value
  {
    value=val;
  }

  void display()
  {
    cout<<"value of class A : "<<value<<endl;
  }
friend void swap(A&,B&); // prototype of friend function
};


// next class
class B
{
  int value;
  public:
void  assign (int val) // for assigning
{
  value=val;
}

void display()
{
  cout<<"value of class B : "<<value<<endl;
}

friend void swap(A&,B&); // prototype of friend functiom
};

// definig the swap function
void swap(A &c,B &d)
{
int temp;
temp =c.value;
c.value = d.value;
d.value = temp;
}


// main funcyion
int main()
{

  A n; // class A objecct
  B m; // class B object
  int a,b;
  cout << "enter x =";
  cin>>a ;
  cout<<"Enter y =";
  cin>>b;
  n.assign(a); //assigning values
  m.assign(b); // assigning values
cout<<endl<<"values before swapnig"<<endl;
  n.display();
  m.display();
  cout<<endl<<"after swapping"<<endl;

  swap(n,m); // swapping
  n.display();
  m.display();

  return 0;
}
