#include<iostream>
#include<dos.h>
#include<conio.h>
using namespace std;
 class BankAccount
 {
 public:
    string Name;
    double AccNo;
    float amount=0,dpstamount=0,wtamount=0;
    void Assigndata()
    {

        cout<<"Enter your name\n";
        cin>>Name;
        cout<<"Enter your Account No.\n";
        cin>>AccNo;
        cout<<"Enter your Balance\n";
        cin>>amount;
    }
    void deposit()
    {
        cout<<"\n\tEnter the amount to deposit\t";
        cin>>dpstamount;
        amount = dpstamount+amount;

     }
     void withdraw()
    {
        cout<<"\n\tYour balance is\t"<<amount<<endl;
        cout<<"\n\tEnter the amount to withdraw\t";
        cin>>wtamount;
        amount= (amount-wtamount);

     }
     void display()
     {
         cout<<"\n\tName\t"<<Name<<"\t";
         cout<<"\n\tBalance\t"<<amount<<endl;

     }

 };
int main()
{
    int x;
    BankAccount acc1;
    acc1.Assigndata();
    do
    {
    cout<<"Enter your choice\n";
    cout<<"1.Deposit money\n";
    cout<<"2.Withdraw Money\n";
    cout<<"3.Display name and balance\n";
    cout<<"4.Exit\n";
    cin>>x;
    switch (x)
   {
       case 1:
               cout<<"To Deposit Money";
               acc1.deposit();
               break;
       case 2: cout<<"To Withdraw Money";
               acc1.withdraw();
                break;
       case 3: cout<<"Display Name and Balance";
               acc1.display();
               break;
       case 4:
      exit(0);
   }
    }while(x<4);
    return 0;

}
