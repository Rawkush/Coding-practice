#include<iostream>
using namespace std;

class A
{
  int value;

public:

  A(int val) // for initiLIAtion
  {
    value=val;
  }

  void display()
  {
    cout<<"value of class B : "<<value;
  }

};

// next class
class B
{
  int value;
  public:
B(int val) // for initialisation
{
  value=val;
}

void display()
{
  cout<<"value of class B : "<<value;
}

};

int main()
{



  return 0;
}
