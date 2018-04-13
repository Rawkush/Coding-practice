#include<iostream>
#include<conio.h>
using namespace std;
class A
{
 public :virtual void f1(){
  cout<<"This is class A function"<<endl;}
};
class B:public A
{
  public:
  void f1(){
  cout<<"This is class B function"<<endl;}
};
int main()
{ A *ptr;
  B ob2;
  ptr=&ob2;
  ptr->f1();
}
