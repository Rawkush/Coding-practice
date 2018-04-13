#include<iostream>
using namespace std;

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
    cout<<"value of class A : "<<value;
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
  cout<<"value of class B : "<<value;
}

friend void swap(A&,B&); // prototype of friend functiom
};

// definig the swap function
void swap(A &c,B&d)
{
int temp;
temp =c.value;
c.value = d.value;
d.value = temp;
}


// main funcyion
int main()
{



  return 0;
}
