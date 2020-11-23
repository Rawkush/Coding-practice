#include<iostream>
using namespace std;

int length(char a[]){
    if(a[0]=='\0')
        return  0;

    return 1+ length(a+1);
}


int main(){

    char str[100]="abc";
    int i= length(str);
    cout<<"length : "<<i;

}
