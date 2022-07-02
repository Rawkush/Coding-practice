#include<iostream>
using namespace std;

// consecutive duplicates remove


void rem(char *c){

    if(c[0]=='\0')
        return;

    rem(c+1);
    if(c[1]!='\0')
        if(c[0]==c[1]){
            int i=1;
            for(;c[i]!='\0';i++)
                c[i-1]=c[i];
            c[i-1]=c[i];
        }
}

int main(){
    char a[]="aaabbccaa";
    rem(a);
    cout<<a;
}
