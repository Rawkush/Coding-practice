#include<iostream>
using namespace std;

void print_keypad(int num, string output){
    string str="";
    if(num<=1){
        cout<<output<<endl;
        return;
    }
    int remainder = num%10;
    num = num/10;
    switch(remainder){
        case 2: str="abc";
            break;
        case 3: str="def";
            break;
        case 4: str = "ghi";
            break;
        case 5: str= "jkl";
            break;
        case 6: str = "mno";
            break;
        case 7 : str="pqrs";
            break;
        case 8: str="tuvw";
            break;
        case 9: str="xyz";
            break;
        default:
            str="";
            break;
    }

    for(int i=0; i<str.length(); i++){
        //include not include ith element
        print_keypad(num, output+str[i]);
    }
}

int main(){
string a="";
    print_keypad(23, a);
    return 0;
}
