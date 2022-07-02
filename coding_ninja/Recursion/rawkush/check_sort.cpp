#include<iostream>
using namespace std;

// check if th array is sorted or not


bool check(int *a, int s){
    if(s==1||s==0) return true;

    if(a[0]>a[1]) return false;

    return check(a+1, s-1);

}


int main(){

    int a[]={1,2,3,4,5,6,1};
    cout<<check(a,7);

}
