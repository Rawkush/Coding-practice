#include<iostream>
using namespace std;

void replaceCharacter(char input[], char c1, char c2, int length) {
    // Write your code here
    if(length==0)
        return;
    replaceCharacter(input+1,c1,c2,length-1);
    if(input[0]==c1)
        input[0]=c2;
}

int main(){
    char a[10]="abacd";
    replaceCharacter(a, 'a','x', 5);
    cout<<a;
    return 0;
}
