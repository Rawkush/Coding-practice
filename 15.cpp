// 15th problem statemnt solution


#include<iostream>
using namespace std;
class complex
{
public:
    int re, img;
Complex( int a, int b)
{        re = a;
         img = b;
}
friend void operator + (complex c, complex d);
};
void operator + (complex c, complex d)
{              complex temp;
       temp.re = c.re + d.re;
       temp.img = c.img + d.img;
       cout<<"Real sum is:  "<<temp.re<<endl;
       cout<<"Imaginary sum is:  "<<temp.img<<endl;
}
int main()
{   complex c1;
     c1.Complex(10,20);
    complex d1;
    d1.Complex(20,30);
    c1+d1;
    return 0;
}
