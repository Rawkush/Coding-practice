#include<iostream>
using namespace std;
class B;
class A
{
        public:
            int a;
    void values(int i)
    {a=i;}
    friend void maxf(A,B);
};
class B
{    int b;
        public:
    void values(int i)
    {b=i;}
    friend void maxf(A,B);
};
void maxf(A x,B y)
{
    if(x.a>=y.b)
        cout<<"\nMaximum is\t"<<x.a<<endl;
    else
        cout<<"\nMaximum is\t"<<y.b<<endl;
}
int main()
{
    A a1;
    int a,b;
    cout<<"Enter two values a and b: \n";
    cin>>a>>b;
    a1.values(a);
    B b1;
    b1.values(b);
    maxf(a1,b1);
    return 0;
}
