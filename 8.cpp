#include <iostream>

using namespace std;
class complex{
int real,imag;
public:
    void set(){
    cout<<"ENTER THE REAL AND IMAGINARY PART : ";
    cin>>real>>imag;
    }
    friend complex sum(complex,complex);
    void display();
};
void complex::display(){
cout<<"the sum of complex number is : "<<real<<"+i"<<imag;
}
complex sum(complex a,complex b){
complex t;
t.real=a.real+b.real;
t.imag=a.imag+b.imag;
return t;
}
int main()
{
    complex a,b,c;
    a.set();
    b.set();
    c=sum(a,b);
    c.display();
    return 0;
}
