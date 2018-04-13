//1st problem statemnt solution

#include<iostream>
using namespace std;
 class Student
 {
 public:
    string Name;
    int RollNo;
    float s1,s2,s3,s4,s5;
    float percent=0;
    void marksandpercentage()
    {

        cout<<"Enter the marks of all 5 subjects\n";
        cin>>s1>>s2>>s3>>s4>>s5;
        percent= ((s1+s2+s3+s4+s5)/5);

    }
    void showresult()
    {
        cout<<"Your percentage is\t"<<percent<<endl;
        if(percent>=81 && percent<=100)
        {
            cout<<"Your grade is\t"<<"A";
        }
        if(percent>=61 && percent<=80)
        {
            cout<<"Your grade is\t"<<"B";
        }
        if(percent>=41 && percent<=60)
        {
            cout<<"Your grade is\t"<<"C";
        }
        if(percent>=33 && percent<=40)
        {
            cout<<"Your grade is\t"<<"D";
        }
        if(percent<33)
        {
            cout<<"Your grade is\t"<<"FAIL";
        }
     }

 };
 int main()
 {
     Student studnt1;
     studnt1.Name= "Jeetu";
     studnt1.RollNo= 022;
     studnt1.marksandpercentage();
     studnt1.showresult();

  return 0;
 }
