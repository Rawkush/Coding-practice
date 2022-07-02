

#include<iostream>
using namespace std;

int pow(int x, int n){
    if(n==0)
        return 1;
    if(n%2==0){
        int a= pow(x,n/2);
        return a*a;
    }
    else{
        int a = pow(x, n/2);
        return x*a*a;
    }

}


int main(){

    int x=10;
    int n=2;
    cout<< pow(x, n);

}
