#include<iostream>
using namespace std;

void getStr(char *s){

    if(s[0]=='\0')
        return ;

    getStr(s+1);

    if(s[0]=='x'){
        int i=1;
        for(;s[i]!='\0';i++)
            s[i-1]=s[i];
        s[i-1]=s[i];
    }
}


int main(){

    char a[]="axnkusxxxh";
    getStr(a);
    cout<< a;

}
