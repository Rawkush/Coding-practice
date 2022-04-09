#include<iostream>
using namespace std;

int first_index(int *a,int n, int s){
    if(a[0]==s) return 0;
    return 1+ first_index(a+1,n-1,s);
 }


 int main(){

    int a[]={5,5,6,5,6};
    int size=5;
    cout<<first_index(a,size,6 );

 }
