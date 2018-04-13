// 17th problem statemnt solution

#include<iostream>
#include<conio.h>
using namespace std;
class complex
{
 public :float real,imag;
   complex()
   {
    real=0,imag=0;

   }
   friend istream& operator>>(istream &in, complex &co1);
   friend complex& operator+(complex &co1,complex &co2);
   friend ostream& operator<<(ostream &out, complex &co2);
};
        istream& operator>>(istream &in,complex &co1){
           in>>co1.real>>co1.imag;
           return in ;
        }
        complex& operator+(complex &co1,complex &co2)
        { complex sum;
        sum.real=co1.real+co2.real;
        sum.imag=co1.imag+co2.imag;
        return sum;

        }
        ostream& operator<<(ostream &out,complex &c){
           out<<c.real<<"+i"<<c.imag;
           return out ;
        }

int main()
{ complex c1,c2,c3;
  cout<<"Enter the complex no. C1`"<<endl;
  cin>>c1;
  cout<<"Enter the complex no. C2`"<<endl;
  cin>>c2;
  c3= c1+c2;
  cout<< "the output is"<<endl;
  cout<<c3;
}
