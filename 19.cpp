#include<iostream>
using namespace std;
int main()
{
    float x = 1000.150,b,c;
    int y,a;
    y=x;
    cout<<"Implicit type conversion is\n";

    cout<<"\t"<<x<<"\n"<<"\t"<<y<<"\n\n";
    cout<<"Explicit type conversion is\n";
    cout<<"\tfor c(float) = a + b\n";
    cout<<"\tEnter the INTEGER value of a:";
    cin>>a;
    cout<<"\tEnter the FLOATING value of b:";
    cin>>b;
    c=(float)a + b;
    cout<<"\tc ="<<c<<endl;
    cout<<"\n";
    return 0;
}
