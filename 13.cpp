#include<iostream>
using namespace std;

class change{
int x,y,z;
public:
    void get(int a, int b, int c)
    {
        x=a;y=b;z=c;
    }

    friend void operator -(change &C)
    {
        C.x=-C.x;
        C.y=-C.y;
        C.z=C.z;
    }
    void display()
    {
        cout<<"\n x="<<x;
        cout<<"\n y="<<y;
        cout<<"\n z="<<z;
    }
};

int main()
{
    change c;
    c.get(10,30,-29);
    cout<<"\n Before calling operator:";
    c.display();
    cout<<"\n After calling operator:";
    -c;
    c.display();
return 0;
}
