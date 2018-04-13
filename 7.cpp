// 7th problem statemnt solution

#include <iostream>

using namespace std;

class Rectangle {

private:
    int area,length,breadth;

public:
    //Simple constructor Definition
    Rectangle(){
        length=9;
        breadth=8;
        cout<<"Simple constructor called\n";
        cout<<"Length= "<<length<<"\nBreadth= "<<breadth<<endl;
    }
    //parameterized constructor
    Rectangle(int x,int y){
    length=x;
    breadth=y;
    }
    void calc();
    void print();
};
void Rectangle::calc(){
area=length*breadth;
}
void Rectangle::print(){
cout<<"Area is : "<<area<<endl;
}

int main()
{
    int l,b;
    Rectangle r1;//simple constructor is called
    r1.calc();
    r1.print();
    cout<<"Enter length and breadth for parameterized constructor: \n";
    cin>>l>>b;
    Rectangle r2(l,b);
    r2.calc();
    r2.print();


    return 0;
}
