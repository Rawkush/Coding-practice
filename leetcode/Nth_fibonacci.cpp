#include<iostream>
using namespace std;
int main(){
    int f1=0,f2=1;
    int sum=0;
    if(n==1)
        return 1;
    for(; n>1; n--){
        sum = f1+f2;
        f1=f2;
        f2=sum;
    }
    return sum;
}