#include<iostream>
using namespace std;

//just to practive recusrion
bool checkPalindrome(char str[], int length) {
    // Write your code here
    if(length==0)
        return true;
    if(str[0]!=str[length-1])
        return false;

    str[length-1]='/0';
    checkPalindrome(str+1, length-2);
}

int main(){
    char a[10]="aca";
    cout<<checkPalindrome(a, 4);
    return 0;
}
