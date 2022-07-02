#include<iostream>
using namespace std;
/**
    abc=>
        a
        b
        c
        ab
        bc
        a
*/
void printSubstrings(char input[]) {
for(int k=0; input[k]!='\0';k++)
    for(int i=k; input[i]!='\0';i++){
        for(int j=k;j<=i; j++){
            cout<<input[j];
        }
        cout<<endl;
    }
}

int main(){
    char inp[]="abc";
    char c[]="";
    printSubstrings(inp);

    return 0;
}
